//
// Created by User on 09/06/2020.
//
#include "activation.h"
#include <cmath>

#define ERROR_BAD_MATRIX "Error: given matrix must have one collumn only"

/**
 * constructor for activation
 * @param actType the type of activation
 */
Activation::Activation(ActivationType actType)
{
    this->_activationType = actType;
}
/**
 * gets the type of activation
 * @return ActivationType
 */
ActivationType Activation::getActivationType() const
{
    return this->_activationType;
}
/**
 * runs the activation functions according to the
 * @param mat the matrix on which to run
 * @return the matrix after the operation
 */
Matrix Activation::operator()(const Matrix &mat) const
{
    if (mat.getCols() != 1)
    {
        std::cerr << ERROR_BAD_MATRIX << std::endl;
        exit(EXIT_FAILURE);
    }
    if (this->getActivationType() == Softmax)
    {
        return this->_softMaxActivate(mat);
    }
    return this->_reluActivate(mat);
}
/**
 * private function to run the relu algorirthm
 * @param mat the matrix on which to run the algorithm
 * @return the matrix after the algorithm
 */
Matrix Activation::_reluActivate(const Matrix &mat) const
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
/**
 * private function to run the soft max algorirthm
 * @param mat the matrix on which to run the algorithm
 * @return the matrix after the algorithm
 */
Matrix Activation::_softMaxActivate(const Matrix &mat) const
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


