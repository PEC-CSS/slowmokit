/**
 * @file methods/metrics/recall.cpp
 *
 * Implementation of the recall main program
 */
#include "recall.hpp"

template <class T>
std::map<T, double> recall(std::vector<T> &pred, std::vector<T> &actual)
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
	std::map<T, double> recallMap;
	std::map<T, int> truePosMap;
	std::map<T, int> falseNegMap;
	for (int i = 0; i < n; i++)
	{
		if (pred[i] == actual[i])
		{
			truePosMap[actual[i]]++;
		}
		else
		{
			falseNegMap[actual[i]]++;
		}
	}

	for (int i = 0; i < numClasses; i++)
	{
		if (truePosMap[i] > 0 || falseNegMap[i] > 0)
		{
			recallMap[i] = (double) (truePosMap[i] /
			                         (double) (truePosMap[i] + falseNegMap[i]));
		}
		else
		{
			recallMap[i] = 1.0;
		}

		double x = recallMap[i];
		const double HALF = 0.5;
		float value = std::lround(x * 100 + HALF);
		recallMap[i] = (float) value / 100;
	}


	return recallMap;
}
