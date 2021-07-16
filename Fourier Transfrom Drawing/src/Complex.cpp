#include "Complex.hpp"


Complex::Complex(double real = 0, double imaginary = 0) {
    this->real = real;
    this->imaginary = imaginary;
}

Complex::~Complex() {

}

double Complex::getReal() const{
    return this->real;
}

double Complex::getImaginary() const{
    return this->imaginary;
}

Complex Complex::operator + (Complex &other){
    return Complex(this->real + other.real, this->imaginary + other.imaginary);
}

Complex Complex::operator - (Complex &other){
    return Complex(this->real - other.real, this->real - other.imaginary);
}
Complex Complex::operator * (Complex &other){
    return Complex(this->real * other.real - this->imaginary * other.imaginary, this->real * other.imaginary + this->imaginary  * other.real);
}

Complex Complex::Conjugate(Complex &c){
    return Complex(c.real, -c.imaginary);
}

double Complex::amplitude(){
    return sqrt(pow(this->real, 2) + pow(this->imaginary, 2));
}

Complex Complex::operator / (Complex &other){
    Complex another = Conjugate(other);
    Complex result = Complex(this->real * another.real - this->imaginary * another.imaginary, this->real * another.imaginary + this->imaginary  * another.real);
    double a = result.amplitude();
    result.real = result.real / a;
    result.imaginary = result.imaginary / a;
    return result;
}

std::ostream& operator << (std::ostream& output, const Complex& c){
    output << "Complex(" << c.getReal() << ", " << c.getImaginary() << ")" << "\n";
    return output;
}