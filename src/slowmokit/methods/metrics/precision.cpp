/**
 * @file methods/metrics/precision.cpp
 *
 * Implementation of the precision main program
 */
#include "precision.hpp"

const double HALF = 0.5;

template <class T>
std::map<T, double> precision(std::vector<T> &pred, std::vector<T> &actual)
{
	if (pred.size() != actual.size())
	{
		throw std::invalid_argument(
		    "Predicted and actual vectors must have same size");
	}
	int n = actual.size();
	std::set<T> s;
	for (int i = 0; i < n; i++)
	{
		s.insert(actual[i]);
	}
	int numClasses = s.size();
	std::map<T, double> precisionMap;
	std::map<T, int> truePosMap;
	std::map<T, int> falsePosMap;

	for (int i = 0; i < n; i++)
	{
		if (pred[i] == actual[i])
		{
			truePosMap[actual[i]]++;
		}
		else
		{
			falsePosMap[pred[i]]++;
		}
	}

	for (int i = 0; i < numClasses; i++)
	{
		if (truePosMap[i] > 0 || falsePosMap[i] > 0)
		{
			precisionMap[i] =
			    (double) (truePosMap[i] /
			              (double) (truePosMap[i] + falsePosMap[i]));
		}
		else
		{
			precisionMap[i] = 1.0;
		}

		double x = precisionMap[i];
		float value = std::lround(x * 100 + HALF);
		precisionMap[i] = (float) value / 100;
	}

	return precisionMap;
}
