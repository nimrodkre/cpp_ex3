//
// Created by User on 09/06/2020.
//
#include "Dense.h"

#define ERROR_DENSE_REQUIRMENT "Given matrix must have only 1 collumn"

Dense::Dense(Matrix &w, Matrix &bias, ActivationType &activationType): _bias(bias), _w(w), _activation(activationType)
{
    if (w.getCols() != 1)
    {
        std::cerr << ERROR_DENSE_REQUIRMENT << std::endl;
        exit(EXIT_FAILURE);
    }
}

Matrix Dense::getBias() const
{
    return _bias;
}

Matrix Dense::getWeights() const
{
    return _w;
}

Activation Dense::getActivation() const
{
    return _activation;
}

Matrix Dense::operator()(Matrix const &mat) const
{
    Matrix retMat((this->getWeights() * mat) + this->getBias());
    return this->getActivation()(retMat);
}




