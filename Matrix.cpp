//
// Created by User on 08/06/2020.
//
#include "Matrix.h"

Matrix::Matrix()
{
    this->_matDims.rows = 1;
    this->_matDims.cols = 1;
    this->_values = new float[1];
    this->_values[0] = 0;
}

Matrix::Matrix(const int rows, const int cols)
{
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

Matrix::Matrix(Matrix &m)
{
    this->_matDims.rows = m.getRows();
    this->_matDims.cols = m.getCols();
    this->_values = new float[this->_matDims.rows * this->_matDims.cols];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            this->_values[cols * i + cols] = m._values[cols * i + cols];
        }
    }
}

int Matrix::getRows() const
{

}