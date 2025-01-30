# Define minimum cmake version.
cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # Export compile commands so cppcheck is aware of compiler options and paths

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

# Set up cppcheck
# Set up cppcheck build directory and cache
set(CPPCHECK_BUILD_DIR "${CMAKE_BINARY_DIR}/cppcheck")
file(MAKE_DIRECTORY "${CPPCHECK_BUILD_DIR}" "${CPPCHECK_BUILD_DIR}/cache")
find_program(CPPCHECK_EXECUTABLE NAMES cppcheck)

set(CPPCHECK_ARGS
    --enable=all
    --check-level=exhaustive
    --inline-suppr
    --max-configs=120
    --std=c++${CMAKE_CXX_STANDARD} # use the standard from cmake
    --cppcheck-build-dir="${CPPCHECK_BUILD_DIR}/cache"
    --project="${CMAKE_BINARY_DIR}/compile_commands.json"
    --suppress=missingIncludeSystem
)

if(CPPCHECK_EXECUTABLE)
    message(STATUS "Found cppcheck: ${CPPCHECK_EXECUTABLE}")
    add_custom_target(
        cppcheck
        COMMAND ${CPPCHECK_EXECUTABLE} ${CPPCHECK_ARGS}
        COMMENT "Running cppcheck static analysis"
    )
else()
    message(WARNING "cppcheck not found. Static analysis will be skipped.")
endif()