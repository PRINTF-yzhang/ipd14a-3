cmake_minimum_required(VERSION 3.3)
project(bitio CXX)
include(.ipd/cmake/CMakeLists.txt)

set(COMMON src/bit_io.cxx)

# Example encoder/decoder for packed ASCII:
add_cxx_program(main src/main.cxx ${COMMON})

