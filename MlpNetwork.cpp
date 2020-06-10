//
// Created by User on 09/06/2020.
//

#include "MlpNetwork.h"
#define ERROR_GIVEN_ARGUMENTS "Error: Given arguments aren't good"
#define ERROR_IMAGE_VECTOR "Error: The given matrix must have 1 column"
#define ERROR_IMAGE_DIMENSIONS "Error: The given matrix isn't in the allowed dimensions"

#define ALLOWED_COLUMNS 1

MlpNetwork::MlpNetwork(Matrix weights[MLP_SIZE], Matrix biases[MLP_SIZE]) : _stage1(weights[0], biases[0], Relu),
                                                                            _stage2(weights[1], biases[1], Relu),
                                                                            _stage3(weights[2], biases[2], Relu),
                                                                            _stage4(weights[3], biases[3], Softmax)
{
    bool good = weights[0].getRows() == weightsDims[0].rows &&
                weights[0].getCols() == weightsDims[0].cols &&
                weights[1].getRows() == weightsDims[1].rows &&
                weights[1].getCols() == weightsDims[1].cols &&
                weights[2].getRows() == weightsDims[2].rows &&
                weights[2].getCols() == weightsDims[2].cols &&
                weights[3].getRows() == weightsDims[3].rows &&
                weights[3].getCols() == weightsDims[3].cols &&
                biases[0].getRows() == biasDims[0].rows &&
                biases[0].getCols() == biasDims[0].cols &&
                biases[1].getRows() == biasDims[1].rows &&
                biases[1].getCols() == biasDims[1].cols &&
                biases[2].getRows() == biasDims[2].rows &&
                biases[2].getCols() == biasDims[2].cols &&
                biases[3].getRows() == biasDims[3].rows &&
                biases[3].getCols() == biasDims[3].cols;
    if (!good)
    {
        std::cerr << ERROR_GIVEN_ARGUMENTS << std::endl;
        exit(EXIT_FAILURE);
    }
}

Digit MlpNetwork::operator()(Matrix &mat)
{
    if (mat.getCols() != ALLOWED_COLUMNS)
    {
        std::cerr << ERROR_IMAGE_VECTOR << std::endl;
        exit(EXIT_FAILURE);
    }

    // now we know that there is only one column
    if (imgDims.rows * imgDims.cols != mat.getRows())
    {
        std::cerr << ERROR_IMAGE_DIMENSIONS << std::endl;
        exit(EXIT_FAILURE);
    }
    this->_getMaxProbability(mat);
    Matrix first = this->_stage1(mat);
    Matrix second = this->_stage2(first);
    Matrix third = this->_stage3(second);
    Matrix last = this->_stage4(third);
    return this->_getMaxProbability(last);
}

Digit MlpNetwork::_getMaxProbability(Matrix &final)
{
    int max = 0;
    for (int i = 0; i < final.getRows(); i++)
    {
        std::cout << "calc" << i << " " << final[i] << std::endl;
        if (final[i] > final[max])
        {
            max = i;
        }
    }
    Digit ret;
    ret.value = max;
    ret.probability = final[max];
    return ret;
}