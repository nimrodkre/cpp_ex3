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
    Matrix& _bias;
    Matrix& _w;
    Activation _activation;
public:
    Dense(Matrix &w, Matrix &bias, ActivationType activationType);
    Matrix getWeights() const;
    Matrix getBias() const;
    Activation getActivation() const;
    Matrix& operator()(Matrix &mat);
};

#endif //CPP_EX3_DENSE_H
