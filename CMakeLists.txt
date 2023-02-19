# Define minimum cmake version.
cmake_minimum_required(VERSION 3.22)

# Define the project name.
project(basicSetup)

# Send libraries to same place
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Add directories
add_subdirectory(kernel)

add_executable(basicSetup main.cpp)

# Add libraries
target_link_libraries(basicSetup PUBLIC kernel)