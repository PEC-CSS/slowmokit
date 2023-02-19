/**
 * @file methods/neighbors/multinomial_nb/multinomial_nb.cpp
 *
 * Implementation of the Multinomial Naive Bayes main program
 */
#include "multinomial_nb.hpp"

template <class T>
double MultinomialNB<T>::priorProb(std::vector<T> yTrain, int label)
{ // Prior-Probability P(y)
	int sum = 0;
	for (int i = 0; i < yTrain.size(); i++)
	{
		if (yTrain[i] == label)
		{
			sum += 1;
		}
	}
	return sum / double(yTrain.size());
}

template <class T>
double MultinomialNB<T>::conditionalProb(std::vector<std::vector<T>> xTrain,
                                         std::vector<T> yTrain, int featureCol,
                                         int featureVal, int label)
{ // Conditional-Probabilty P(x=f1 / y=class)
	int denominator = 0, numerator = 0;
	std::set<int> varies_values;
	for (int i = 0; i < yTrain.size(); i++)
	{
		if (yTrain[i] == label)
		{ // Check if label of feature is same as output looking for
			denominator++; // All values with output_class we are looking for
			varies_values.insert(xTrain[i][featureCol]);
			if (xTrain[i][featureCol] == featureVal)
			{
				numerator++; // numerator increase only when that feature
				             // consists of value same as value in testing
				             // feature
			}
		}
	}
	return (numerator + 1) /
	    double(denominator +
	           varies_values
	               .size()); // as it is multinomial nb so to avoid overfitting
	// numerator+1 -> because if word do not exist in training but exist in
	// testing denominator + number_of_different_values_in_feature
}

template <class T>
int MultinomialNB<T>::fit_predict(std::vector<std::vector<T>> xTrain,
                                  std::vector<T> yTrain, std::vector<T> classes,
                                  std::vector<T> xTest)
{
	int n_features = xTrain[0].size();

	std::vector<double> postProbs;

	std::vector<int>::iterator label; // different ouput labels
	for (label = classes.begin(); label != classes.end(); label++)
	{ // iterating over all labels (P(y=y1,y2,y3....))
		double likelihood = 1.0;
		for (int i = 0; i < n_features; i++)
		{
			double cond = conditionalProb(xTrain, yTrain, i, xTest[i], *label);
			likelihood += log10(cond); // Log10 of computed conditionl
			                           // probabilty => Log10(P(x=x1 / y=label))
		}

		double prior = priorProb(yTrain, *label);
		double post = prior * likelihood;
		postProbs.push_back(post);
	}
	double sumpropProbs = 0.0;
	int max = 0;
	for (int i = 0; i < postProbs.size(); i++)
	{ // Iterating over all labels computed values to check if any negative
	  // value
		// exists, if so then direclty values are compared else we will compute
		// value/sum
		if (postProbs[i] < 0)
		{
			sumpropProbs = 1;
			break;
		}
		sumpropProbs += postProbs[i];
	}
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