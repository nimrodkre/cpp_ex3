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

// Insert Activation class here...
class Activation
{
private:
    ActivationType _activationType;
    Matrix _relu(Matrix const &mat) const;
    Matrix _softmax(Matrix const &mat) const;
public:
    Activation(ActivationType actType);
    ActivationType getActivationType() const;
    Matrix operator()(Matrix const &mat) const;
};

#endif //ACTIVATION_H
