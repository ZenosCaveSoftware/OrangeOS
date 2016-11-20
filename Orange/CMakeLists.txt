set(CMAKE_ASM_NASM_OBJECT_FORMAT win)
enable_language(ASM_NASM)
set(CMAKE_C_FLAGS "-Wall -Wextra -pedantic -std=c11 -O0 -fno-common -fomit-frame-pointer -nostdlib -lgcc -DNDEBUG")

set(CMAKE_ASM_NASM_FLAGS -i${CMAKE_CURRENT_LIST_DIR}/include/)


set(Orange_SRCS)

include_directories(${CMAKE_CURRENT_LIST_DIR}/include)

include(${CMAKE_CURRENT_LIST_DIR}/common/CMakeLists.txt)

if(EXISTS ${CMAKE_CURRENT_LIST_DIR}/arch/${arch}/CMakeLists.txt)
	include(${CMAKE_CURRENT_LIST_DIR}/arch/${arch}/CMakeLists.txt)
endif()

if(EXISTS ${CMAKE_CURRENT_LIST_DIR}/arch/${arch}/linker.ld)
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Xlinker -T\"${CMAKE_CURRENT_LIST_DIR}/arch/${arch}/linker.ld\"")
endif()

add_executable(KRNL ${Orange_SRCS})
set_target_properties(KRNL PROPERTIES VERSION ${Orange_VERSION})

