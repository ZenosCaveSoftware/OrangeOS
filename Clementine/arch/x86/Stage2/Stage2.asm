; -------------------------------------------------------------
; Clementine Bootloader:
;	Please refer to the LICENSE file you should have recieved
;	with this software.
;
;	Stage2.asm
;	  
;	-- Luke Smith	
; -------------------------------------------------------------

org		500h
bits	16

jmp	Stage2

;-------------------------;
; Preprocessor directives ;
;-------------------------;

%include "stdio.inc"
%include "Gdt.inc"
%include "A20.inc"
%include "Fat12.inc"
%define IMAGE_PMODE_BASE 0x100000
%define IMAGE_RMODE_BASE 0x3000

ImageName     db "KRNL    SYS"
ImageSize     db 0
msgLoading	db "Loading...",0x0A,0x00
msgFailure	db 0x0A, 0x00, "Error Loading: Press any key to reboot...", 0x0A, 0x00
;--------------------------;
; Boot Stage2			   ;
;	- Store BIOS info	   ;
;	- Load and exec KERNEL ;
;	- Install GDT and A20  ;		
;	- Enter protected mode ;
;	- Jump to Stage3       ;
;--------------------------;
Stage2:
	cli
	xor ax, ax
	mov ds, ax
	mov es, ax
	mov ax, 0x0
	mov ss, ax
	mov sp, 0xFFFF
	sti

	call InstallGDT

	call EnableA20_Bios

	mov si, msgLoading
	call Puts16
	
	call LoadRoot
	
	mov ebx, 0
	mov bp, IMAGE_RMODE_BASE 
	mov si, ImageName
	call LoadFile
	mov dword [ImageSize], ecx

	cmp ax, 0
	je EnterStage3
	mov si, msgFailure
	call Puts16
	mov ah, 0
	int 0x16
	int 0x19
	cli
	hlt

EnterStage3:
	cli
	mov eax, cr0
	or 	eax, 1
	mov cr0, eax

	jmp KERN_CODE_DESC:Stage3


; -------------------------	;
;  Boot Stage3			    ;
; ------------------------- ;

bits 32

BadImage db "*** FATAL: Invalid or corrupt kernel image. Halting system.", 0

Stage3:
	mov	ax, KERN_DATA_DESC
 	mov	ds, ax
 	mov ss, ax
 	mov es, ax
 	mov	esp, 90000h

CopyImage:
 	mov	eax, dword [ImageSize]
  	movzx ebx, word [BytesPerSector]
  	mul	ebx
  	mov	ebx, 4
  	div	ebx
   	cld
   	mov esi, IMAGE_RMODE_BASE
   	mov	edi, IMAGE_PMODE_BASE
   	mov	ecx, eax
   	rep	movsd
   	
TestImage:
	mov ebx, [IMAGE_PMODE_BASE+60]
	add ebx, IMAGE_PMODE_BASE
	mov esi, ebx
	mov edi, ImageSig
   	cmpsw
   	je EXECUTE
   	mov ebx, BadImage
   	call Puts32
   	cli
   	hlt

ImageSig db 'PE'

EXECUTE:
	add ebx, 24
	mov eax, [ebx]
	add ebx, 20-4
	mov ebp, dword [ebx]
	add ebx, 12
	mov eax, dword [ebx]
	add ebp, eax
	cli
	
	call ebp
	
	cli
	hlt