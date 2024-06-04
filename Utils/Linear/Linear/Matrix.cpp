#include "Matrix.h"

Matrix::Matrix(int rows, int cols) : m(rows), n(cols)
{
    this->entries = std::vector<Complex>();
    this->entries.reserve(rows * cols);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            entries.push_back(Complex(0, 0));
        }
    }
}

Matrix::Matrix(int rows, int cols, std::initializer_list<Complex> values) : m(rows), n(cols) {
    this->entries = std::vector<Complex>();
    this->entries.reserve(rows * cols);

    int i = 0;
    for (const auto &elem : values) {
        entries.push_back(elem);
        i++;
    }
}

Complex Matrix::at(unsigned int i, unsigned int j)
{
    if (m < i || n < j) {
        throw std::out_of_range("Specified element out of range");
    }

    return this->entries.at(m * i + j);
}

void Matrix::set(unsigned int i, unsigned int j, Complex val)
{
    if (m < i || n < j) {
        throw std::out_of_range("Specified element out of range");
    }
    int range = m * i + j;
    this->entries.at(range) = val;
}

Matrix& Matrix::transpose() 
{
    Matrix* result = new Matrix(this->n, this->m);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result->set(j, i, this->at(i, j));
        }
    }

    return *result;
}

Matrix& Matrix::add(Matrix& right)
{
    if (this->m != right.m || this->n != right.n)
    {
        throw std::invalid_argument("Dimensions of matrix differ.");
    }

    Matrix* result = new Matrix(this->m, this->n);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            Complex c1 = this->at(i, j);
            Complex c2 = right.at(i, j);
            result->set(i, j, Complex::add(c1,c2));
        }
    }

    return *result;
}

Matrix& Matrix::sclMul(Complex& right)
{
    Matrix* result = new Matrix(this->m, this->n);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            Complex c1 = this->at(i, j);
            result->set(i, j, Complex::mul(c1, right));
        }
    }

    return *result;
}

Matrix& Matrix::vecMul(Matrix& right)
{
    if (this->n != right.m)
    {
        throw std::invalid_argument("Incompatable dimension!");
    }

    int newRows = this->m;
    int newCols = right.n;

    Matrix* result = new Matrix(newRows, newCols);

    for (int i = 0; i < newRows; i++) {
        for (int j = 0; j < newCols; j++) {
            Complex sum = Complex(0.0f, 0.0f);
            for (int x = 0; x < n; x++) {
                Complex c1 = this->at(i, x);
                Complex c2 = right.at(x, i);
                Complex mul = Complex::mul(c1, c2);
                sum = sum.add(mul);
            }
            result->set(i, j, sum);
        }
    }

    return *result;
}

Complex Matrix::det()
{
    if (m != n)
    {
        throw std::invalid_argument("Not a square matrix!");
    }

    if (m == 2 && n == 2)
    {
        Complex a = this->at(0, 0);
        Complex b = this->at(0, 1);
        Complex c = this->at(1, 0);
        Complex d = this->at(1, 1);
        Complex ad = Complex::mul(a, d);
        Complex bc = Complex::mul(b, c);
        return Complex::sub(ad, bc);
    }

    Complex sum = Complex(0.0f, 0.0f);
    for (int j = 0; j < n; j++) {
        Matrix min = minor(0, j);
        Complex detMin = min.det();
        Complex cofactorSign = Complex((j % 2 == 0) ? 1.0f : -1.0f, 0.0f);
        Complex cofactor = this->at(0, j);
        Complex signedCofactor = Complex::mul(cofactorSign, cofactor);

        sum = Complex::add(
            sum,
            Complex::mul(signedCofactor, detMin));
    }
    return sum;
}

Matrix Matrix::minor(int delRow, int delCol)
{
    if (m < 1 || n < 1)
    {
        throw std::invalid_argument("Matrix too small to generate minor matrix!");
    }

    Matrix result = Matrix(this->m - 1, this->n - 1);
    int mi = 0;
    int mj = 0;
    for (int i = 0; i < m; i++)
    {
        if (i == delRow) continue;
        for (int j = 0; j < n; j++)
        {
            if (j == delCol) continue;
            else {
                double real = this->at(i, j).getReal();
                double imag = this->at(i, j).getImag();
                Complex c = Complex(real, imag);
                printf("%d %d\n", mi, mj);
                result.set(mi, mj, c);
                mj++;
            }
        }
        mj = 0;
        mi++;
    }
    return result;
}