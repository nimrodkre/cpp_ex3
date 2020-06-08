//
// Created by User on 08/06/2020.
//
#include "Matrix.h"

#define ERROR_USER_DIMENSIONS "Error: rows and cols must be positive integers"
#define ERROR_FAILED_ADDITION "Error: unable to add matrixes as dimensions are different"
#define ERROR_OUT_OF_RANGE "Error: out of range"
#define ERROR_BAD_STREAM "Error: stream given is bad"
#define THRESHOLD_PRINT 0.1

Matrix::Matrix()
{
    this->_matDims.rows = 1;
    this->_matDims.cols = 1;
    this->_values = new float[1];
    this->_values[0] = 0;
}

Matrix::Matrix(const int rows, const int cols)
{
    if (rows < 1 || cols < 1)
    {
        std::cerr << ERROR_USER_DIMENSIONS << std::endl;
        exit(EXIT_FAILURE);
    }
    this->_matDims.rows = rows;
    this->_matDims.cols = cols;
    this->_values = new float[rows * cols];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            this->_values[cols * i + cols] = 0;
        }
    }
}

Matrix::Matrix(Matrix const &m)
{
    this->_matDims.rows = m.getRows();
    this->_matDims.cols = m.getCols();
    this->_values = new float[this->getRows() * this->getCols()];
    for (int i = 0; i < this->getRows(); i++)
    {
        for (int j = 0; j < this->getCols(); j++)
        {
            this->_values[this->getCols() * i + this->getCols()] = m._values[this->getCols() * i +
                                                                                     this->getCols()];
        }
    }
}

Matrix::~Matrix()
{
    delete[] this->_values;
}

int Matrix::getRows() const
{
    return this->_matDims.rows;
}

int Matrix::getCols() const
{
    return this->_matDims.cols;
}

Matrix &Matrix::vectorize()
{
    this->_matDims.rows *= this->getCols();
    this->_matDims.cols = 1;
    return *this;
}

void Matrix::plainPrint() const
{
    for (int i = 0; i < this->getRows(); i++)
    {
        for (int j = 0; j < this->getCols(); j++)
        {
            std::cout << this->_values[i * this->getCols()+ j] << " ";
        }
        std::cout << std::endl;
    }
}

Matrix& Matrix::operator=(Matrix const &mat)
{
    if (this == &mat)
    {
        return *this;
    }
    delete[] this->_values;
    this->_matDims.rows = mat.getRows();
    this->_matDims.cols = mat.getCols();
    this->_values = new float[mat.getRows() * mat.getCols()];
    for (int i = 0; i < this->getRows(); i++)
    {
        for (int j = 0; j < this->getCols(); j++)
        {
            this->_values[this->getCols() * i + this->getCols()] = mat._values[this->getCols() * i +
                                                                                     this->getCols()];
        }
    }
    return *this;
}
Matrix Matrix::operator*(const float scalar) const
{
    Matrix mat(this->getRows(), this->getCols());
    for (int i = 0; i < this->getRows(); i++)
    {
        for(int j = 0; j < this->getCols(); i++)
        {
            mat(i, j) = (*this)(i, j) * scalar;
        }
    }
    return mat;
}

Matrix Matrix::operator+(Matrix const &mat) const
{
    Matrix retMat = *this;
    retMat += mat;
    return retMat;
}

Matrix& Matrix::operator+=(const Matrix& mat)
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
float& Matrix::operator()(int i, int j) const
{
    if (i < 0 || j < 0 || i >= this->getRows() || j >= this->getCols())
    {
        std::cerr << ERROR_OUT_OF_RANGE << std::endl;
        exit(EXIT_FAILURE);
    }
    return this->_values[i * this->getCols() + j];
}
float& Matrix::operator[](long int i) const
{
    if (i < 0 || i >= this->getCols() * this->getRows())
    {
        std::cerr << ERROR_OUT_OF_RANGE << std::endl;
        exit(EXIT_FAILURE);
    }
    return this->_values[i];
}

Matrix operator*(float scalar, Matrix const &mat)
{
    return mat*scalar;
}

// WHAT SHOULD I RETURN??????
void operator>>(std::ifstream &in, Matrix &mat)
{
    long int expectedSize = mat.getCols() * mat.getRows();

    //check the size of the ifstream
    in.seekg(0, std::ios_base::end);
    if (in.tellg() != expectedSize * sizeof(float))
    {
        std::cerr << ERROR_BAD_STREAM << std::endl;
        exit(EXIT_FAILURE);
    }

    long int index = 0;
    in.seekg(0, std::ios_base::beg);
    // we know that the given file is in correct size
    while (in.good() && index < expectedSize)
    {
        in.read((char *) &mat[index], sizeof(float));
        index++;
    }
    if (!in.good() || index != expectedSize - 1)
    {
        std::cerr << ERROR_BAD_STREAM << std::endl;
        exit(EXIT_FAILURE);
    }
}

//RETURN?
void operator<<(std::ostream &out, const Matrix &mat)
{
    for (int i = 0; i < mat.getRows(); i++)
    {
        for (int j = 0; j < mat.getCols(); j++)
        {
            if (mat(i, j) <= THRESHOLD_PRINT)
            {
                out << "**";
            }
            else
            {
                out << "  ";
            }
        }
        out << std::endl;
    }

}