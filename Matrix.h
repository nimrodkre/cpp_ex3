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

/**
 * Matrix class
 */
class Matrix
{
private:
    /**
     * holds matrix dimensions
     */
    MatrixDims _matrixDims;
    /**
     * array with float values
     */
    float *_values;
public:
    /**
     * constructor which builds matrix with rows and columns
     * with all numbers 0
     * @param rows the number of rows
     * @param cols the number of colmuns
     */
    Matrix(int rows, int cols);
    /**
     * defualt constructor with 1 row and 1 column with 0
     */
    Matrix();
    /**
     * constructor which recieves matrix as input
     * @param m the matrix to copy from
     */
    Matrix(const Matrix &m);
    /**
     * destructor of the matrix
     */
    ~Matrix();

    /**
     * gets the number of rows in the matrix
     * @return
     */
    int getRows() const;
    /**
     * gets the number of rows in the matrix
     * @return
     */
    int getCols() const;
    /**
     * turns the matrix to a vector
     * @return
     */
    Matrix& vectorize();
    /**
     * prints the matrix
     */
    void plainPrint() const;
    /**
     * copies the given matrix to our matrix
     * @param mat the matrix to copy
     * @return matrix reference to this
     */
    Matrix& operator=(Matrix const &mat);
    /**
     * multiply the matrix by scalar
     * @param scalar the float to multiply by
     * @return the matrix multiplied
     */
    Matrix operator*(float scalar) const;
    /**
     * multiply matrixes
     * @param mat the matrix to multiply by
     * @return the multiplied matrix
     */
    Matrix operator*(Matrix const &mat);
    /**
     * add matrixes
     * @param mat the matrix to add
     * @return added matrixes
     */
    Matrix operator+(Matrix const &mat) const;
    /**
     * adds matrix to our matrix
     * @param mat the matrix to add
     * @return new matrix
     */
    Matrix operator+=(const Matrix& mat);
    /**
     * gets the float value in given location
     * @param i rows
     * @param j column
     * @return ref to float of value
     */
    float& operator()(int i, int j) const;
    /**
     * gets the float value to the given location
     * @param i location to get
     * @return ref to float
     */
    float& operator[](long int i) const;
    /**
     * multiplies matrix by scalar
     * @param scalar the float to multiply by
     * @param our matrix
     * @return multiplied matrix
     */
    friend Matrix operator*(float scalar, Matrix const &mat);
    /**
     * reads the file data
     * @param in the file to read from
     * @param mat the matrix to read data to
     * @return the file data
     */
    friend std::ifstream& operator>>(std::ifstream &in, Matrix &mat);
    /**
     * output of matrix
     * @param out the output stream
     * @param mat the matrix to build stream of
     * @return output stream
     */
    friend std::ostream& operator<<(std::ostream &out, const Matrix &mat);
};

#endif //MATRIX_H