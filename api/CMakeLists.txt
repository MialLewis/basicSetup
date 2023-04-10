set(SRC_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/helloWorld.cpp
)

#create library from src and inc
add_library(api ${SRC_FILES})
target_include_directories(api PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)

# Add libraries
target_link_libraries(api PRIVATE kernel)

# Setup python interface and link API lib
pybind11_add_module(basicSetupApi ${CMAKE_CURRENT_SOURCE_DIR}/pythonInterface/apiBindings.cpp)
target_link_libraries(basicSetupApi PRIVATE api)