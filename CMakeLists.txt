# ########## Project Setup ##########
cmake_minimum_required(VERSION 2.8)
project(Orange)
set(Orange_MAJOR_VERSION 0)
set(Orange_MINOR_VERSION 0)
set(Orange_PATCH_VERSION 1)
set(Orange_VERSION ${Orange_MAJOR_VERSION}.${Orange_MINOR_VERSION}.${Orange_PATCH_VERSION})

set(arch x86)

# Modules
foreach(module Orange Clementine LibOC)
    if(EXISTS ${CMAKE_CURRENT_LIST_DIR}/${module}/CMakeLists.txt)
        add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/${module})
    endif()
endforeach()