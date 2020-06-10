//Activation.h
#ifndef ACTIVATION_H
#define ACTIVATION_H

#include "Matrix.h"

/**
 * @enum ActivationType
 * @brief Indicator of activation function.
 */
enum ActivationType
{
    Relu,
    Softmax
};

/**
 * Class in charge of actiating the algorithms
 */
class Activation
{
private:
    /**
     * The type of the action wanted
     */
    ActivationType _activationType;
    /**
     * private function to run the relu algorirthm
     * @param mat the matrix on which to run the algorithm
     * @return the matrix after the algorithm
     */
    Matrix _relu_activate(const Matrix  &mat) const;
    /**
     * private function to run the soft max algorirthm
     * @param mat the matrix on which to run the algorithm
     * @return the matrix after the algorithm
     */
    Matrix _softMax_activate(const Matrix &mat) const;
public:
    /**
     * constructor for activation
     * @param actType the type of activation
     */
    Activation(ActivationType actType);
    /**
     * gets the type of activation
     * @return ActivationType
     */
    ActivationType getActivationType() const;
    /**
     * runs the activation functions according to the
     * @param mat the matrix on which to run
     * @return the matrix after the operation
     */
    Matrix operator()(const Matrix &mat) const;
};

#endif //ACTIVATION_H
