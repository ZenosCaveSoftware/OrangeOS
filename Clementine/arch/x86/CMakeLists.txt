set(CMAKE_ASM_NASM_OBJECT_FORMAT bin)
set(CMAKE_ASM_NASM_LINK_EXECUTABLE "cp <OBJECTS> <TARGET>")
enable_language(ASM_NASM)

set(CMAKE_ASM_NASM_FLAGS -i${CMAKE_CURRENT_LIST_DIR}/inc/)


set(Clementine_Stage1_SRCS ${CMAKE_CURRENT_LIST_DIR}/Stage1/Stage1.asm)
set(Clementine_Stage2_SRCS ${CMAKE_CURRENT_LIST_DIR}/Stage2/Stage2.asm)

set(CMAKE_NASM_LINK_EXECUTABLE nasm)
add_executable(Stage1 ${Clementine_Stage1_SRCS})
add_executable(KRNLDR ${Clementine_Stage2_SRCS})

set_target_properties(Stage1 PROPERTIES LINKER_LANGUAGE ASM_NASM)
set_target_properties(KRNLDR PROPERTIES LINKER_LANGUAGE ASM_NASM)
