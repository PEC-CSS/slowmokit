/**
 * @file methods/metrics/classification_report.hpp
 *
 * Easy include to show the classification report of data
 */

#include "classification_report.hpp"
template<class T>

ClassificationReport<T>::ClassificationReport(std::vector<T> &trueValue,
                                              std::vector<T> &predictedValue)
{
	this->trueValue = trueValue;
	this->predictedValue = predictedValue;
	ClassificationReport<T>::printReport();
}

template<class T>
void ClassificationReport<T>::confusionMatrix(std::vector<T> &trueValue,
                                              std::vector<T> &predictedValue)
{
	int n = trueValue.size();

	for (int i = 0; i < n; i++)
	{
		classes[trueValue[i]]++;
		if (trueValue[i] == predictedValue[i])
		{
			truePositive[trueValue[i]]++;
		}
		if (trueValue[i] != predictedValue[i])
		{
			falseNegative[trueValue[i]]++;
			falsePositive[predictedValue[i]]++;
		}
	}
	// For True Negative, had to do it separately :crycatok:
	for (auto it : classes)
	{
		T classNumber = it.first;
		for (int i = 0; i < n; i++)
		{
			if (trueValue[i] != classNumber && predictedValue[i] != classNumber)
			{
				trueNegative[classNumber]++;
			}
		}
	}
}

template<class T>
std::map<T, double> ClassificationReport<T>::precision()
{
	// True Positive / (True Positive + False Positive)
	std::map<T, double> precisionMap;
	for (auto it : classes)
	{
		T classNumber = it.first;
		if (truePositive[classNumber] > 0 || falsePositive[classNumber] > 0)
		{
			precisionMap[classNumber] =
			    (double) (truePositive[classNumber] /
			              (double) (truePositive[classNumber] +
			                        falsePositive[classNumber]));
		}
		else
		{
			precisionMap[classNumber] = 0.0;
		}

		// Trick to make all numbers upto 2 decimal place
		double x = precisionMap[classNumber];
		float value = (int) (x * 100 + .5);
		precisionMap[classNumber] = (float) value / 100;
	}
	return precisionMap;
}

template<class T>
std::map<T, double> ClassificationReport<T>::recall()
{
	// True Positive / (True Positive + False Negative)
	std::map<T, double> recallMap;
	for (auto it : classes)
	{
		T classNumber = it.first;
		if (truePositive[classNumber] > 0 || falseNegative[classNumber] > 0)
		{
			recallMap[classNumber] =
			    (double) ((double) truePositive[classNumber] /
			              ((double) truePositive[classNumber] +
			               (double) falseNegative[classNumber]));
		}
		else
		{
			recallMap[classNumber] = 0.0;
		}
		double x = recallMap[classNumber];
		float value = (int) (x * 100 + .5);
		recallMap[classNumber] = (float) value / 100;
	}
	return recallMap;
}

template<class T>
std::map<T, double> ClassificationReport<T>::f1Score()
{
	// 2 * Precision * Recall / (Precision + Recall)
	std::map<T, double> precisionMap, recallMap;
	precisionMap = precision();
	recallMap = recall();
	std::map<T, double> f1ScoreMap;
	for (auto it : classes)
	{
		T classNumber = it.first;
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

template<class T>
std::map<T, double> ClassificationReport<T>::accuracy()
{
	// (True Positive  + True Negative)/ (True Positive + False Positive + False
	// Negative + True Negative)
	std::map<T, double> accuracyMap;
	for (auto it : classes)
	{
		T classNumber = it.first;
		accuracyMap[classNumber] =
		    (double) (((double) truePositive[classNumber] +
		               (double) trueNegative[classNumber]) /
		              ((double) truePositive[classNumber] +
		               (double) falseNegative[classNumber] +
		               (double) falsePositive[classNumber] +
		               (double) trueNegative[classNumber]));

		double x = accuracyMap[classNumber];
		float value = (int) (x * 100 + .5);
		accuracyMap[classNumber] = (float) value / 100;
	}
	return accuracyMap;
}

template<class T>
void ClassificationReport<T>::printReport()
{
	std::cout << "Class-No. Precision Accuracy  Recall   F1_Score\n";
	std::map<int, double> precisionMap = precision();
	std::map<int, double> accuracyMap = accuracy();
	std::map<int, double> recallMap = recall();
	std::map<int, double> f1ScoreMap = f1Score();
	for (auto classNumber : classes)
	{
		std::cout << std::setw(4) << classNumber.first << std::setw(10)
		          << precisionMap[classNumber.first] << std::setw(10)
		          << accuracyMap[classNumber.first] << std::setw(11)
		          << recallMap[classNumber.first] << std::setw(10)
		          << f1ScoreMap[classNumber.first] << std::endl;
	}
}
