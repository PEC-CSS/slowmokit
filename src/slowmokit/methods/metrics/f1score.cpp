/**
 * @file methods/metrics/f1score.cpp
 *
 * Implementation of the f1Score main program
 */
#include "f1score.hpp"
#include "precision.cpp"
#include "recall.cpp"

template <class T>
std::map<T, double> f1Score(std::vector<T> &pred, std::vector<T> &actual)
{
	// 2 * Precision * Recall / (Precision + Recall)
	std::map<T, double> precisionMap;
	std::map<T, double> recallMap;
	precisionMap = precision(pred, actual);
	recallMap = recall(pred, actual);
	std::map<T, double> f1ScoreMap;
	for (int i = 0; i < precisionMap.size(); i++)
	{
		T classNumber = i;
		if (precisionMap[classNumber] == 0 || recallMap[classNumber] == 0)
		{
			f1ScoreMap[classNumber] = 0;
		}
		else
		{
			f1ScoreMap[classNumber] = (2 * (double) precisionMap[classNumber] *
			                           (double) recallMap[classNumber]) /
			    ((double) precisionMap[classNumber] +
			     (double) recallMap[classNumber]);

			double x = f1ScoreMap[classNumber];
			float value = (int) (x * 100 + .5);
			f1ScoreMap[classNumber] = (float) value / 100;
		}
	}
	return f1ScoreMap;
}
