/**
 * @file methods/linear_models/linear_regression/linear_regression.hpp
 *
 * The header file including the linear regression algorithm
 */

#ifndef SLOWMOKIT_LINEAR_REGRESSION_HPP
#define SLOWMOKIT_LINEAR_REGRESSION_HPP

#include "core.hpp"

template <class T>
class LinearRegression
{
private:
    std::vector<T> coefficients;
    int epochs = 100;
    double learningRate = 0.01;

public:
    void fit(std::vector<std::vector<T>> x, std::vector<T> y);

    std::vector<T> predict(std::vector<std::vector<T>> x);

    void printCoefficients();
};

#endif //SLOWMOKIT_LINEAR_REGRESSION_HPP
