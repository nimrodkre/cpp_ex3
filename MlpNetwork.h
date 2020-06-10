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

// Insert MlpNetwork class here...
class MlpNetwork
{
private:
    Dense _stage1;
    Dense _stage2;
    Dense _stage3;
    Dense _stage4;
    Digit _getMaxProbability(Matrix &final);
public:
    MlpNetwork(Matrix weights [MLP_SIZE], Matrix biases[MLP_SIZE]);
    Digit operator()(Matrix &mat);
};

#endif // MLPNETWORK_H
