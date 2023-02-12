/**
 * @file methods/metrics/classification_report.hpp
 *
 * Easy include to show the classification report of data
 */

#ifndef SLOWMOKIT_CLASSIFICATION_REPORT_HPP
#define SLOWMOKIT_CLASSIFICATION_REPORT_HPP
#include "../../core.hpp"

/**
 * Takes predicted and actual values of classes
 * @param predictedValue -> predicted values
 * @param trueValue -> true values
 * @returns the classification report
 * @throws domain_error exception when size of the two vectors is not equal
 */

template <class T>
class ClassificationReport
{
	private:
	std::vector<T> trueValue;
	std::vector<T> predictedValue;
	std::map<T, int> classes, truePositive, falsePositive, trueNegative,
	    falseNegative;

	public:
	ClassificationReport(std::vector<T> &, std::vector<T> &);

	/**
	 * @throws domain_error exception when size of the two vectors is not equal
	 */
	void confusionMatrix(std::vector<T> &, std::vector<T> &);


	/**
	 * @brief tells us precision values for all the classes
	 * @returns the map with all the precision values
	 */
	std::map<T, double> precision();


	/**
	 * @brief tells us recall values for all the classes
	 * @returns the map with all the recall values
	 */
	std::map<T, double> recall();


	/**
	 * @brief tells us fiScore values for all the classes
	 * @returns the map with all the f1scores values
	 */
	std::map<T, double> f1Score();


	/**
	 * @brief tells us accuracy values for all the classes
	 * @returns the map with all the accuracy values
	 */
	std::map<T, double> accuracy();


	/**
	 * @brief Prints all the classification report parameters in the form of
	 * table
	 * @returns nothing except happiness
	 */
	void printReport();
};

#endif // SLOWMOKIT_CLASSIFICATION_REPORT_HPP
