//
// Created by User on 08/06/2020.
//
#ifndef CPP_EX3_DENSE_H
#define CPP_EX3_DENSE_H

#include "Matrix.h"
#include "Activation.h"

/**
 * Class which holds the weight, bias, and the activation wanted
 */
class Dense
{
private:
    /**
     * holds the bias matrix
     */
    Matrix& _bias;
    /**
     * holds the weight matrix
     */
    Matrix& _w;
    /**
     * holds the activation type
     */
    Activation _activation;
public:
    /**
     * constructor for dense
     * @param w the Weight matrix
     * @param bias
     * @param activationType
     */
    Dense(Matrix &w, Matrix &bias, ActivationType activationType);
    /**
     * Gets copy of the weights matrix
     * @return
     */
    Matrix getWeights() const;
    /**
     * get copy of bias matrix
     * @return
     */
    Matrix getBias() const;
    /**
     * get activation matrix copy
     * @return
     */
    Activation getActivation() const;
    /**
     * runs the activation wanted on the given matrix with the weights and bias
     * @param mat the matrix on which to run
     * @return the change on the given matrix
     */
    Matrix& operator()(Matrix &mat);
};

#endif //CPP_EX3_DENSE_H
