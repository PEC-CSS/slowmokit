/**
 * @file methods/linear_model/logistic_regression/logistic_regression.hpp
 *
 * The header file including the logistic regression algorithm
 */

#ifndef SLOWMOKIT_LOGISTIC_REGRESSION_HPP
#define SLOWMOKIT_LOGISTIC_REGRESSION_HPP

#include "../../../core.hpp"

template <class T>
class LogisticRegression
{
	int batchSize = -1;

	private:
	std::vector<std::vector<T>> beta; // Initializing beta i.e weights ->
	                                  // (output_classes * numbers_of_features)
	/**
	 * @brief computes softmax of all x values
	 *
	 * @param x values for which we are computing softmax
	 * @return std::vector<double> softmax values
	 */
	std::vector<double> softmax(std::vector<T> x);
	/**
	 * @brief Cross Entropy
	 *
	 * @param y output values one hot encoded
	 * @param qi predicted values
	 * @return double cross entropy
	 */
	double crossLogEntropy(std::vector<int> y, std::vector<T> qi);
	/**
	 * @brief computes loss
	 *
	 * @param x training values
	 * @param beta weights
	 * @return double loss value
	 */
	double evalL(std::vector<std::vector<T>> x, std::vector<std::vector<int>> y,
	             std::vector<std::vector<T>> beta);
	/**
	 * @brief Mini-batch gradient descent
	 *
	 * @param x training x values
	 * @param y training output values
	 * @param alpha double value which multiplied with gradient descent
	 * @param numEpochs number of epochs
	 * @param verbose require to print which epoch is going on
	 * @return std::vector<std::vector<double>>
	 */
	std::vector<std::vector<double>>
	logRegMbgd(std::vector<std::vector<double>> x,
	           std::vector<std::vector<int>> y, double alpha, int numEpochs,
	           bool verbose);

	public:
	/**
	 * @brief training
	 *
	 * @param x training x values
	 * @param y training y values
	 * @param alpha double value which multiplied with gradient descent
	 * @param numEpochs number of epochs
	 * @param batchSize size of batch
	 * @param verbose require to print which epoch is going on
	 */
	void fit(std::vector<std::vector<T>> x, std::vector<int> y, double alpha,
	         int numEpochs, bool verbose, int batchSize = -1);
	/**
	 * @brief Predict value for testing
	 *
	 * @param x testing value
	 * @return std::vector<double> one hot encoded probabilities for each class
	 */
	std::vector<double> predict(std::vector<T> x);
};

#endif // SLOWMOKIT_LOGISTIC_REGRESSION_HPP