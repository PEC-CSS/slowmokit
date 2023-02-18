/**
 * @file methods/neighbors/bernoulli_nb/bernoulli_nb.hpp
 *
 * The header file including the Bernoulli Naive Bayes algorithm
 */

#ifndef SLOWMOKIT_BERNOULLI_NB_HPP
#define SLOWMOKIT_BERNOULLI_NB_HPP

#include "../../../core.hpp"

template <class T>
class BernoulliNB
{
	private:
	/**
	@brief Function Prior probability
	@param yTrain to compute P(y=y1) and label y1
	@returns double value of prior Probability
	*/
	double priorProb(std::vector<T> yTrain, int label);
	/**
	@brief Function conditional Probabilty
	@param xTrain 2-d all x training values
	@param yTrain all 1-d y training values
	@param featureCol for which feature column we are finding conditional prob
	@param featureVal for what value in that feature we are looking for
	conditional prob
	@param label y value looking for
	@returns double value of conditional probability
	*/
	double conditionalProb(std::vector<std::vector<T>> xTrain,
	                       std::vector<T> yTrain, int featureCol,
	                       int featureVal, int label);

	public:
	/**
	@brief Function fit and predict the output
	@param xTrain 2-d training values
	@param yTrain 1-d y training values
	@param xTest testing values
	@returns predicted value for each test according to bernoulli naive bayes
	model
	*/
	int fitPredict(std::vector<std::vector<T>> xTrain, std::vector<T> yTrain,
	               std::vector<T> xTest);
};

#endif