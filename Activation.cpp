//
// Created by User on 09/06/2020.
//
#include "Activation.h"
#include <math.h>

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
    if (this->getActivationType() == Relu)
    {
        return this->_relu(mat);
    }
    return this->_softmax(mat);
}

Matrix Activation::_relu(Matrix const &mat) const
{
    Matrix reluMax(mat);
    for (int i = 0; i < reluMax.getRows(); i++)
    {
        for (int j = 0; j < reluMax.getCols(); j++)
        {
            if (reluMax(i, j) < 0)
            {
                reluMax(i, j) = 0;
            }
        }
    }
    return reluMax;
}

Matrix Activation::_softmax(Matrix const &mat) const
{
    Matrix softMax(mat);
    float sum = 0;

    for (int i = 0; i < softMax.getRows(); i++)
    {
        softMax[i] = std::exp(softMax[i]);
        sum += softMax[i];
    }

    return (1 / sum) * softMax;
}


