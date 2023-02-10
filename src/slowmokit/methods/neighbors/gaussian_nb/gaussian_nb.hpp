/**
 * @file methods/neighbors/gaussian_nb/gaussian_nb.hpp
 *
 * The header file including the Gaussian Naive Bayes algorithm
 */

#ifndef SLOWMOKIT_GAUSSIAN_NB_HPP
#define SLOWMOKIT_GAUSSIAN_NB_HPP

#include "../../../core.hpp"

template<class T> class GaussianNB
{
	private:
	/**
	 * @brief Condtional Probability of Gaussian Naive Bayes
	 *
	 * @param mean mean of all column values
	 * @param variance variance of all column values
	 * @param feature feature in column looking for
	 * @return double
	 */
	double conditionalProb(int mean, int variance, int feature);

	public:
	/**
	 * @brief Fit predict at same time
	 *
	 * @param xTrain all training 2-d double x values
	 * @param yTrain all trainng 1-d int y values
	 * @param xTest testing values
	 * @param classes number of classes in output
	 * @return int class predicted for test case
	 */
	int fitPredict(std::vector<std::vector<T>> xTrain, std::vector<int> yTrain,
	               std::vector<T> xTest, std::vector<int> classes);
};

#endif // SLOWMOKIT_GAUSSIAN_NB_HPP