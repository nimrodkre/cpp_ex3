// Matrix.h

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <fstream>

/**
 * @struct MatrixDims
 * @brief Matrix dimensions container
 */
typedef struct MatrixDims
{
    int rows, cols;
} MatrixDims;

// Insert Matrix class here...
class Matrix
{
private:
    MatrixDims _matDims;
    float *_values;
public:
    Matrix(int rows, int cols);
    Matrix();
    Matrix(Matrix const &m);
    ~Matrix();

    int getRows() const;
    int getCols() const;
    Matrix& vectorize();
    void plainPrint() const;

    Matrix& operator=(Matrix const &mat);
    Matrix operator*(float scalar) const;
    Matrix operator*(Matrix const &mat);
    Matrix operator+(Matrix const &mat) const;
    Matrix& operator+=(const Matrix& mat);
    float& operator()(int i, int j) const;
    float& operator[](long int i) const;

};

Matrix operator*(float scalar, Matrix const &mat);
std::ifstream& operator>>(std::ifstream &in, Matrix &mat);
std::ostream& operator<<(std::ostream &out, const Matrix &mat);
#endif //MATRIX_H
