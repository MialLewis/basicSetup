#include <boost/python.hpp>
#include <iostream>

class ComplexNumber {
private:
    double m_real;
    double m_imaginary;

public:
    ComplexNumber() : m_real(0), m_imaginary(0) {};
    ComplexNumber(double real, double imaginary) : m_real(real), m_imaginary(imaginary) {};
    const double getReal() const { return m_real; }
    const double getImaginary() const { return m_imaginary; }

    ComplexNumber ComplexNumber::operator+(const ComplexNumber& rhs) { return ComplexNumber(m_real + rhs.getReal(), m_imaginary + rhs.getImaginary()); }
    void print() { std::cout << m_real << " + " << m_imaginary << "i"; }
};



int add(int a, int b) {
    return a + b;
}

BOOST_PYTHON_MODULE(api_boost) {
    using namespace boost::python;
    def("add", add);

    class_<ComplexNumber>("ComplexNumber", init<double, double>())
        .def("__add__", &ComplexNumber::operator+, (arg("left"), arg("right")))
        .def("print", &ComplexNumber::print);
}
