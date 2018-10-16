cmake_minimum_required(VERSION 3.12)
project(A01_pgm)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(A01_pgm
        cmake-build-debug/A01_pgm.cbp
        cmake-build-debug/A01_pgm.exe
        cmake-build-debug/A01_pgm.ilk
        cmake-build-debug/A01_pgm.pdb
        cmake-build-debug/cmake_install.cmake
        cmake-build-debug/CMakeCache.txt
        cmake-build-debug/Makefile
        CMakeLists.txt
        main.cpp)
