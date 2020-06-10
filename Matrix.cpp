//
// Created by User on 08/06/2020.
//
#include "Matrix.h"

#define ERROR_USER_DIMENSIONS "Error: rows and cols must be positive integers"
#define ERROR_FAILED_ADDITION "Error: unable to add matrixes as dimensions are different"
#define ERROR_OUT_OF_RANGE "Error: out of range"
#define ERROR_MATRIX_MULTIPLICATION "Error: can't multiply matrixes"
#define ERROR_BAD_STREAM "Error: stream given is bad"
#define THRESHOLD_PRINT 0.1
/**
 * defualt constructor with 1 row and 1 column with 0
 */
Matrix::Matrix()
{
    this->_matrixDims.rows = 1;
    this->_matrixDims.cols = 1;
    this->_values = new float[1];
    (*this)(0, 0) = 0;
}
/**
 * constructor which builds matrix with rows and columns
 * with all numbers 0
 * @param rows the number of rows
 * @param cols the number of colmuns
 */
Matrix::Matrix(int rows, int cols)
{
    if (rows < 1 || cols < 1)
    {
        std::cerr << ERROR_USER_DIMENSIONS << std::endl;
        exit(EXIT_FAILURE);
    }

    this->_matrixDims.rows = rows;
    this->_matrixDims.cols = cols;
    this->_values = new float[rows * cols];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            (*this)(i, j) = 0;
        }
    }
}
/**
 * constructor which recieves matrix as input
 * @param m the matrix to copy from
 */
Matrix::Matrix(const Matrix &m)
{
    this->_matrixDims.rows = m.getRows();
    this->_matrixDims.cols = m.getCols();
    this->_values = new float[this->getRows() * this->getCols()];
    for (int i = 0; i < this->getRows(); i++)
    {
        for (int j = 0; j < this->getCols(); j++)
        {
            this->_values[this->getCols() * i + j] = m._values[this->getCols() * i +
                                                                                     j];
        }
    }
}
/**
 * destructor of the matrix
 */
Matrix::~Matrix()
{
    delete[] this->_values;
}
/**
 * gets the number of rows in the matrix
 * @return
 */
int Matrix::getRows() const
{
    return this->_matrixDims.rows;
}
/**
 * gets the number of cols in the matrix
 * @return
 */
int Matrix::getCols() const
{
    return this->_matrixDims.cols;
}
/**
 * turns the matrix to a vector
 * @return
 */
Matrix &Matrix::vectorize()
{
    this->_matrixDims.rows *= this->getCols();
    this->_matrixDims.cols = 1;
    return *this;
}
/**
 * prints the matrix
 */
void Matrix::plainPrint() const
{
    for (int i = 0; i < this->getRows(); i++)
    {
        for (int j = 0; j < this->getCols(); j++)
        {
            std::cout << this->_values[i * this->getCols() + j] << " ";
        }
        std::cout << std::endl;
    }
}
/**
 * copies the given matrix to our matrix
 * @param mat the matrix to copy
 * @return matrix reference to this
 */
Matrix& Matrix::operator=(Matrix const &mat)
{
    if (this == &mat)
    {
        return *this;
    }
    delete[] this->_values;
    this->_matrixDims.rows = mat.getRows();
    this->_matrixDims.cols = mat.getCols();
    this->_values = new float[mat.getRows() * mat.getCols()];
    for (int i = 0; i < this->getRows(); i++)
    {
        for (int j = 0; j < this->getCols(); j++)
        {
            this->_values[this->getCols() * i + j] = mat._values[this->getCols() * i +
                                                                                     j];
        }
    }
    return *this;
}
/**
 * multiply the matrix by scalar
 * @param scalar the float to multiply by
 * @return the matrix multiplied
 */
Matrix Matrix::operator*(const float scalar) const
{
    Matrix mat(*this);
    for (int i = 0; i < this->getRows(); i++)
    {
        for(int j = 0; j < this->getCols(); j++)
        {
            mat(i, j) *= scalar;
        }
    }
    return mat;
}
/**
 * add matrixes
 * @param mat the matrix to add
 * @return added matrixes
 */
Matrix Matrix::operator+(Matrix const &mat) const
{
    Matrix retMat = *this;
    retMat += mat;
    return retMat;
}
/**
 * adds matrix to our matrix
 * @param mat the matrix to add
 * @return new matrix
 */
Matrix Matrix::operator+=(const Matrix& mat)
{
    if (this->getRows() != mat.getRows() || this->getCols() != mat.getCols())
    {
        std::cerr << ERROR_FAILED_ADDITION << std::endl;
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < this->getRows(); i++)
    {
        for (int j = 0; j < this->getCols(); j++)
        {
            (*this)(i, j) += mat(i, j);
        }
    }

    return *this;
}
/**
 * gets the float value in given location
 * @param i rows
 * @param j column
 * @return ref to float of value
 */
float& Matrix::operator()(int i, int j) const
{
    if (i < 0 || j < 0 || i >= this->getRows() || j >= this->getCols())
    {
        std::cerr << ERROR_OUT_OF_RANGE << std::endl;
        exit(EXIT_FAILURE);
    }
    return this->_values[i * this->getCols() + j];
}
/**
 * gets the float value to the given location
 * @param i location to get
 * @return ref to float
 */
float& Matrix::operator[](long int i) const
{
    if (i < 0 || i >= (this->getCols() * this->getRows()))
    {
        std::cerr << ERROR_OUT_OF_RANGE << std::endl;
        exit(EXIT_FAILURE);
    }
    return this->_values[i];
}
/**
 * multiplies matrix by scalar
 * @param scalar the float to multiply by
 * @return multiplied matrix
 */
Matrix operator*(float scalar, Matrix const &mat)
{
    return mat*scalar;
}
/**
 * multiplies matrix by scalar
 * @param scalar the float to multiply by
 * @param our matrix
 * @return multiplied matrix
 */
Matrix Matrix::operator*(Matrix const &mat)
{
    if (this->getCols() != mat.getRows())
    {
        std::cerr << ERROR_MATRIX_MULTIPLICATION << std::endl;
        exit(EXIT_FAILURE);
    }
    Matrix retMat(this->getRows(), mat.getCols());
    for (int i  = 0; i < this->getRows(); i++)
    {
        for (int j = 0; j < mat.getCols(); j++)
        {
            for (int k = 0; k < this->getCols(); k++)
            {
                retMat(i, j) += (*this)(i, k) * mat(k, j);
            }
        }
    }
    return retMat;
}
/**
 * reads the file data
 * @param in the file to read from
 * @param mat the matrix to read data to
 * @return the file data
 */
std::ifstream& operator>>(std::ifstream &in, Matrix &mat)
{
    in.seekg(0, std::ios_base::beg);
    long int start = in.tellg();
    in.seekg(0, std::ios_base::end);
    if ((long unsigned int)(in.tellg() - start) != mat.getCols() * mat.getRows() * sizeof(float))
    {
        std::cerr << ERROR_BAD_STREAM << std::endl;
        exit(EXIT_FAILURE);
    }

    in.seekg(0, std::ios_base::beg);
    int index = 0;
    while (index < (int)mat.getCols() * mat.getRows())
    {
        if (!in.good())
        {
            std::cerr << ERROR_BAD_STREAM << std::endl;
            exit(EXIT_FAILURE);
        }
        in.read((char *) &mat[index], sizeof(float));
        index++;
    }

    //maybe ruined at end?
    if (!in.good())
    {
        std::cerr << ERROR_BAD_STREAM << std::endl;
        exit(EXIT_FAILURE);
    }
    return in;
}
/**
 * output of matrix
 * @param out the output stream
 * @param mat the matrix to build stream of
 * @return output stream
 */
std::ostream& operator<<(std::ostream &out, const Matrix &mat)
{
    for (int i = 0; i < mat.getRows(); i++)
    {
        for (int j = 0; j < mat.getCols(); j++)
        {
            if (mat(i, j) <= THRESHOLD_PRINT)
            {
                out << "  ";
            }
            else
            {
                out << "**";
            }
        }
        out << std::endl;
    }
    return out;
}