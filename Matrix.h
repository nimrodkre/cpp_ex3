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
    Matrix(const int rows, const int cols);
    Matrix();
    Matrix(Matrix &m);
    ~Matrix();

    int getRows() const;
    int getCols() const;
    Matrix& vectorize();
    void plainPrint() const;

    Matrix& operator=(const Matrix& mat);
    Matrix operator*(float scalar) const;
    Matrix operator*(const Matrix& mat, const float scalar) const;
    Matrix operator+(const float scalar) const;
    Matrix& operator+=(const Matrix& mat);
    float& operator()(const int i, const int j) const;
    float& operator[](const int i) const;
    std::ifstream& operator>>(std::ifstream &in, Matrix &mat);
    std::ostream& operator<<(std::ostream &out, const Matrix &mat);
};
#endif //MATRIX_H
