set(CMAKE_C_FLAGS "-std=c11 -O2 -fpic -fno-common -fomit-frame-pointer -nostdlib -lgcc -DNDEBUG")
set(LibOC_SRCS)

include_directories(${CMAKE_CURRENT_LIST_DIR}/include)

include(${CMAKE_CURRENT_LIST_DIR}/common/CMakeLists.txt)

if(EXISTS ${CMAKE_CURRENT_LIST_DIR}/arch/${arch}/CMakeLists.txt)
	include(${CMAKE_CURRENT_LIST_DIR}/arch/${arch}/CMakeLists.txt)
endif()

add_library(orangec ${LibOC_SRCS})
set_target_properties(orangec PROPERTIES VERSION ${Orange_VERSION})
