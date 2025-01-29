# Define minimum cmake version.
cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Define the project name.
project(basicSetup)

# Send libraries to same place
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Find Pybind conda package
find_package(pybind11 REQUIRED)

# Add directories
add_subdirectory(kernel)
add_subdirectory(api)

add_executable(basicSetup main.cpp)

# Add libraries
target_link_libraries(basicSetup PUBLIC kernel api)
