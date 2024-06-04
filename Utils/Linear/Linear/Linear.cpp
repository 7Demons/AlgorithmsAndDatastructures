// Linear.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Complex.h"
#include "Matrix.h"

int main()
{
    auto c1 = Complex(1.0f, 1.0f);
    auto c2 = Complex(2.0f, 2.0f);
    auto c3 = Complex(3.0f, 3.0f);
    auto c4 = Complex(4.0f, 4.0f);
    auto c5 = Complex(5.0f, 0.0f);
    Complex c8 = Complex::getConjugate(c1);

    auto m1 = Matrix(2, 2,
        {c1, c2, c3, c4}
    );
    auto m2 = Matrix(3, 3,
        { c5, c2, c3, c5, c2, c3, c1, c2, c3 }
    );

    auto r1 = Complex(1.0f, 0.0f);
    auto r2 = Complex(2.0f, 0.0f);
    auto r3 = Complex(3.0f, 0.0f);
    auto r4 = Complex(4.0f, 0.0f);
    auto r5 = Complex(2.0f, 0.0f);
    auto r6 = Complex(1.0f, 0.0f);
    auto r7 = Complex(4.0f, 0.0f);
    auto r8 = Complex(-1.0f, 0.0f);
    auto r9 = Complex(4.0f, 0.0f);

    auto m3 = Matrix(3, 3, { r1, r2, r3, r4, r5, r6, r7, r8, r9 });
    auto det = m3.det();

    printf("det x, y real: %f  imag: %f\n",det.getReal(), det.getImag());


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
