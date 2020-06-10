//
// Created by User on 09/06/2020.
//
#include "activation.h"
#include <cmath>

#define ERROR_BAD_MATRIX "Error: given matrix must have one collumn only"

Activation::Activation(ActivationType actType)
{
    this->_activationType = actType;
}

ActivationType Activation::getActivationType() const
{
    return this->_activationType;
}

Matrix Activation::operator()(const Matrix &mat) const
{
    if (mat.getCols() != 1)
    {
        std::cerr << ERROR_BAD_MATRIX << std::endl;
        exit(EXIT_FAILURE);
    }
    if (this->getActivationType() == Softmax)
    {
        return this->_softMax_activate(mat);
    }
    return this->_relu_activate(mat);
}

Matrix Activation::_relu_activate(const Matrix &mat) const
{
    if (mat.getCols() != 1)
    {
        std::cerr << ERROR_BAD_MATRIX << std::endl;
        exit(EXIT_FAILURE);
    }

    Matrix reluMax(mat);
    for (int i = 0; i < reluMax.getRows(); i++)
    {
        if (reluMax[i] < 0)
        {
            reluMax[i] = 0;
        }
    }
    return reluMax;
}

Matrix Activation::_softMax_activate(const Matrix &mat) const
{
    if (mat.getCols() != 1)
    {
        std::cerr << ERROR_BAD_MATRIX << std::endl;
        exit(EXIT_FAILURE);
    }

    Matrix softMax(mat);
    float sum = 0;

    for (int i = 0; i < softMax.getRows(); i++)
    {
        sum += std::exp(softMax[i]);
        softMax[i] = std::exp(softMax[i]);
    }
    return softMax * (1/sum);
}


