/**
 * @file methods/linear_models/linear_regression/linear_regression.hpp
 *
 * The header file including the linear regression algorithm
 */

#ifndef SLOWMOKIT_LINEAR_REGRESSION_HPP
#define SLOWMOKIT_LINEAR_REGRESSION_HPP

#include "../../../core.hpp"


const double LEARNING_RATE=0.01;
const int EPOCHS=100;
template <class T>
class LinearRegression
{
	private:
	std::vector<T> coefficients;
	int epochs = EPOCHS;
	double learningRate = LEARNING_RATE;

	public:
	LinearRegression(int = EPOCHS, double = LEARNING_RATE);

	void fit(std::vector<std::vector<T>>, std::vector<T>);

	std::vector<T> predict(std::vector<std::vector<T>>);

	void printCoefficients();
};

#endif // SLOWMOKIT_LINEAR_REGRESSION_HPP
