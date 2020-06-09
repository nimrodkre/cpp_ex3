//
// Created by User on 08/06/2020.
//
#ifndef CPP_EX3_DENSE_H
#define CPP_EX3_DENSE_H

#include "Matrix.h"
#include "Activation.h"

class Dense
{
private:
    Matrix _w;
    Matrix _bias;
    Activation _activation;
public:
    Dense(Matrix &w, Matrix &bias, ActivationType &activationType);
    Matrix getWeights() const;
    Matrix getBias() const;
    Activation getActivation() const;
    Matrix operator()(Matrix const &mat) const;
};

#endif //CPP_EX3_DENSE_H
