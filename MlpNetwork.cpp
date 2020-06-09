//
// Created by User on 09/06/2020.
//

#include "MlpNetwork.h"

MlpNetwork::MlpNetwork(Matrix *weights, Matrix *biases): _stage1(weights[0], biases[0], Relu),
{

}

