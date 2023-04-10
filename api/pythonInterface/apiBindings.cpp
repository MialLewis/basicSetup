#include <pybind11/pybind11.h>
#include "basicSetupApi/helloWorld.h"

namespace py = pybind11;

PYBIND11_MODULE(basicSetupApi, m) {
    m.doc() = "Python bindings for the api C++ library";

    py::class_<basicSetup::api::helloWorld>(m, "helloWorld")
        .def(py::init<>(), "Default constructor that prints 'Hello Word'")
        .def(py::init<const std::string &>(), "Overloaded constructor that takes a string input and prints 'Hello World, my name is inputString'");
}