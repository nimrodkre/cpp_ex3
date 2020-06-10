//MlpNetwork.h

#ifndef MLPNETWORK_H
#define MLPNETWORK_H

#include "Matrix.h"
#include "Digit.h"
#include "Dense.h"

#define MLP_SIZE 4

const MatrixDims imgDims = {28, 28};
const MatrixDims weightsDims[] = {{128, 784}, {64, 128}, {20, 64}, {10, 20}};
const MatrixDims biasDims[]    = {{128, 1}, {64, 1}, {20, 1},  {10, 1}};

/**
 * in charge of building our network
 */
class MlpNetwork
{
private:
    /**
     * first stage of network
     */
    Dense _stage1;
    /**
     * second stage of network
     */
    Dense _stage2;
    /**
     * third stage of network
     */
    Dense _stage3;
    /**
     * fourth stage of network
     */
    Dense _stage4;
    /**
     * finds the maximum probaibiliy in the given vector
     * @param final the final vector
     * @return  the digit of the best probability
     */
    Digit _getMaxProbability(Matrix &final);
    /**
     * checks that the given user inputs are good - according to the constants
     * @param weights the weights
     * @param biases biases
     * @return true if good else false
     */
    bool _checkDensities(const Matrix weights[MLP_SIZE], const Matrix biases[MLP_SIZE]) const;
public:
    /**
     * constructor for the network
     * @param weights weights
     * @param biases biases
     */
    MlpNetwork(Matrix weights [MLP_SIZE], Matrix biases[MLP_SIZE]);
    /**
     * applies the network on the given vector
     * @param mat out image
     * @return digit with the number we saw
     */
    Digit operator()(Matrix &mat);
};

#endif // MLPNETWORK_H
