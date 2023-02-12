/**
 * @file methods/neighbors/gaussian_nb/gaussian_nb.cpp
 *
 * Implementation of the Gaussian Naive Bayes main program
 */

#include "gaussian_nb.hpp"

template<class T>
double conditionalProb(int mean, int variance, int feature)
{
	// Conditional probabilty  P(x=f1 / y=class) = __________1____________ * e^(
	// -_____(feature-mean)^2_____)
	//                                            ((2*pi*variance^2)^(1/2))    (
	//                                            2 * variance^2      )
	double den = pow((2 * 3.14 * variance * variance), 0.5);
	double insideExp = -1 * pow((feature - mean), 2);
	insideExp /= (2 * variance * variance);
	double num = exp(insideExp);
	return num / den;
};

template<class T>
int fitPredict(std::vector<std::vector<T>> xTrain, std::vector<int> yTrain,
               std::vector<T> xTest, std::vector<int> classes)
{
	int nFeatures = xTrain[0].size();

	std::vector<double> postProbs;

	std::vector<double> means(xTrain[0].size());
	std::vector<double> variances(xTrain[0].size());

	double sum = 0.0;

	for (int i = 0; i < xTrain[0].size(); i++)
	{
		for (int j = 0; j < xTrain.size(); j++)
		{
			sum += xTrain[j][i];
		}
		means[i] = sum / double(xTrain.size()); // Computing means
		sum = 0.0;
	}

	sum = 0.0;

	for (int i = 0; i < xTrain[0].size(); i++)
	{
		for (int j = 0; j < xTrain.size(); j++)
		{
			sum += pow((xTrain[j][i] - means[i]), 2);
		}
		variances[i] = pow((sum / double(xTrain.size())),
		                   0.5); // Computing variances of each column
		sum = 0.0;
	}

	double sumpropProbs = 0.0;
	for (int j = 0; j < classes.size(); j++)
	{
		double likelihood = 1.0;
		for (int i = 0; i < nFeatures; i++)
		{
			double cond =
			    conditionalProb(means[i], variances[i],
			                    xTest[i]); // Conditional prob of each column
			likelihood *= cond;
		}

		int sum = 0;
		for (int i = 0; i < yTrain.size(); i++)
		{
			if (yTrain[i] == classes[j])
			{
				sum += 1;
			}
		}
		double prior = sum / double(yTrain.size());

		double post = prior * likelihood;
		postProbs.push_back(post);
		sumpropProbs += post;
	}
	int max = 0;
	for (int i = 0; i < postProbs.size(); i++)
	{
		postProbs[i] /= sumpropProbs;
		if (postProbs[i] > postProbs[max])
		{
			max = i;
		}
	}
	return max;
};