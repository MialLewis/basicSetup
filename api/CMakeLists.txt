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

### Boost Python API
find_package(Boost REQUIRED COMPONENTS python313)
find_package(Python3 REQUIRED COMPONENTS Interpreter Development)

# Create boost api library
add_library(api_boost MODULE ${CMAKE_CURRENT_SOURCE_DIR}/pythonInterface/apiBindingsBoost.cpp)
target_include_directories(api_boost PRIVATE ${Boost_INCLUDE_DIRS} ${Python3_INCLUDE_DIRS})
target_link_libraries(api_boost PRIVATE Boost::boost Boost::python313 ${Python3_LIBRARIES})
set_target_properties(api_boost PROPERTIES PREFIX "" SUFFIX ".pyd")