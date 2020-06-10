//
// Created by User on 09/06/2020.
//
#include "Dense.h"

#define ERROR_DENSE_REQUIRMENT "Given matrix must have only 1 collumn"
/**
* constructor for dense
* @param w the Weight matrix
* @param bias
* @param activationType
*/
Dense::Dense(Matrix &w, Matrix &bias, ActivationType activationType): _bias(bias), _w(w), _activation(activationType)
{
    if (bias.getCols() != 1)
    {
        std::cerr << ERROR_DENSE_REQUIRMENT << std::endl;
        exit(EXIT_FAILURE);
    }
}
/**
 * get copy of bias matrix
 * @return
 */
Matrix Dense::getBias() const
{
    return _bias;
}
/**
 * Gets copy of the weights matrix
 * @return
 */
Matrix Dense::getWeights() const
{
    return _w;
}
/**
 * get activation matrix copy
 * @return
 */
Activation Dense::getActivation() const
{
    return _activation;
}
/**
 * runs the activation wanted on the given matrix with the weights and bias
 * @param mat the matrix on which to run
 * @return the change on the given matrix
 */
Matrix& Dense::operator()(Matrix &mat)
{
    mat = this->getActivation()(_w * mat + _bias);
    return mat;
}




