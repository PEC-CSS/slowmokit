/**
 * @file methods/linear_model/linear_regression/linear_regression.cpp
 *
 * Implementation of the Linear Regression main program
 */

#include "linear_regression.hpp"

template <class T>
LinearRegression<T>::LinearRegression(int epochs, double learningRate)
{
	this->epochs = epochs;
	this->learningRate = learningRate;
}

template <class T>
void LinearRegression<T>::fit(std::vector<std::vector<T>> x, std::vector<T> y)
{
	if (x.empty() || y.empty())
		throw "Make sure that you have atleast one train example";
	if (x.size() != y.size())
		throw "Number of features and target must be equal";
	int trainExampleSize = x.size(), featureSize = x[0].size();
	if (featureSize == 0)
		throw "Feature size should be at least 1";
	coefficients.clear();
	coefficients.resize(featureSize + 1);

	for (int epoch = 0; epoch < epochs; epoch++)
	{
		std::vector<T> yPred;
		for (int example = 0; example < trainExampleSize; example++)
		{
			T currentY = coefficients[0];
			for (int feature = 0; feature < featureSize; feature++)
				currentY += coefficients[feature + 1] * x[example][feature];
			yPred.push_back(currentY);
		}
		for (int example = 0; example < trainExampleSize; example++)
			coefficients[0] -=
			    learningRate * (yPred[example] - y[example]) / trainExampleSize;
		for (int feature = 0; feature < featureSize; feature++)
		{
			for (int example = 0; example < trainExampleSize; example++)
				coefficients[feature + 1] -= learningRate *
				    (yPred[example] - y[example]) * x[example][feature] /
				    trainExampleSize;
		}
	}
}

template <class T>
std::vector<T> LinearRegression<T>::predict(std::vector<std::vector<T>> x)
{
	std::vector<T> yPred;
	int trainExampleSize = x.size(), featureSize = x[0].size();
	for (int example = 0; example < trainExampleSize; example++)
	{
		T currentY = coefficients[0];
		for (int feature = 0; feature < featureSize; feature++)
			currentY += coefficients[feature + 1] * x[example][feature];
		yPred.push_back(currentY);
	}
	return yPred;
}

template <class T>
void LinearRegression<T>::printCoefficients()
{
	for (int i = 0; i < coefficients.size(); i++)
		std::cout << "Θ" << i << ": " << coefficients[i] << std::endl;
}
