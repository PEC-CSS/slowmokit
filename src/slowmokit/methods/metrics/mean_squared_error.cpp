/**
 * @file methods/metrics/mean_squared_error.cpp
 *
 * Implementation of the MSE main program
 */
#include "mean_squared_error.hpp"
template <class T>
double meanSquaredError(std::vector<T> &actual, std::vector<T> &pred)
{
	if (actual.size() != pred.size())
	{
		throw std::invalid_argument(
		    "Actual and Predicted vectors must have same size");
	}

	double sum = 0.0;
	for (int i = 0; i < actual.size(); i++)
	{
		sum += (actual[i] - pred[i]) * (actual[i] - pred[i]);
	}
	return sum / actual.size();
}
