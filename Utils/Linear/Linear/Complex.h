#pragma once
#include <cmath>

class Complex {
private:
    double re, im;
public:
    Complex(double real = 0.0f, double imag = 0.0f) : re(real), im(imag) {}

    double getReal() { return re; }
    double getImag() { return im; }

    void setReal(double real) { re = real; }
    void setImag(double imag) { im = imag; }

    Complex& add(Complex& right) {
        Complex* result = new Complex(
            this->getReal() + right.getReal(),
            this->getImag() + right.getImag());
        return *result;
    }

    static Complex& add(Complex& left, Complex& right) {
        return left.add(right);
    }

    Complex& sub(Complex& right) {
        Complex* result = new Complex(
            this->getReal() - right.getReal(),
            this->getImag() - right.getImag());
        return *result;
    }

    static Complex& sub(Complex& left, Complex& right) {
        return left.sub(right);
    }

    Complex& mul(Complex& right) {
        Complex* result = new Complex(
            this->getReal() * right.getReal() - this->getImag() * right.getImag(),
            this->getReal() * right.getImag() + this->getImag() * right.getReal());
        return *result;
    }

    static Complex& mul(Complex& left, Complex& right) {
        return left.mul(right);
    }

    Complex& div(Complex& right) {
        Complex* result = new Complex(
            (this->getReal() * right.getReal() + this->getImag() * right.getImag()) /
            (right.getReal() * right.getReal() + right.getImag() * right.getImag()),
            (this->getImag() * right.getReal() - this->getReal() * right.getImag()) /
            (right.getReal() * right.getReal() + right.getImag() * right.getImag()));
        return *result;
    }

    static Complex& div(Complex& left, Complex& right) {
        return left.div(right);
    }

    Complex& getConjugate() {
        Complex* result = new Complex(this->getReal(), -this->getImag());
        return *result;
    }

    static Complex& getConjugate(Complex& c) {
        return c.getConjugate();
    }

    double magnitude() {
        return std::sqrt(this->getReal() * this->getReal() + this->getImag() * this->getImag());
    }

};
