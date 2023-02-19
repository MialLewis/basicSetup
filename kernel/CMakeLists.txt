set(SRC_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/printer.cpp
)

#create library from src and inc
add_library(kernel ${SRC_FILES})
target_include_directories(kernel PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)