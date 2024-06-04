#pragma once

#include <vector>
#include <iostream>
#include <exception>
#include "Complex.h"

class Matrix
{
private:
	int m, n;
	std::vector<Complex> entries; // starting from top left to bottom right.

public:
	Matrix(int rows, int cols);
	Matrix(int rows, int cols, std::initializer_list<Complex> values);

	Complex at(unsigned int i, unsigned int j);
	void set(unsigned int i, unsigned int j, Complex val);

	Matrix& add(Matrix& right);
	Matrix& sclMul(Complex& scalar);
	Matrix& vecMul(Matrix& right);
	Matrix& transpose();
	Complex det();
	Matrix minor(int delRow, int delCol);
	//Matrix& invert();

	//Matrix& switchRow(int row1, int row2);
	//Matrix& multRow(int row, Complex scalar);  //
	//Matrix& rowAddition(int row1, int row2, Complex row2Scalar); //Ra = Ra + CRa

};

