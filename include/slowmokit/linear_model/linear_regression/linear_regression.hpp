
/**
 * @file linear_model/linear_regression/linear_regression.hpp
 *
 * Header file including linear_regression algorithm.
 */

#ifndef SLOWMOKIT_LINEAR_REGRESSION_HEADER_HPP
#define SLOWMOKIT_LINEAR_REGRESSION_HEADER_HPP

#include <slowmokit/core.hpp>


const double LEARNING_RATE = 0.01;
const int EPOCHS = 100;

namespace slkt
{
	template <class T>
	class LinearRegression
	{
		private:
		std::vector<T> coefficients;
		int epochs = EPOCHS;
		double learningRate = LEARNING_RATE;

		public:
		LinearRegression(int = EPOCHS, double = LEARNING_RATE);

		void fit(std::vector<std::vector<T>>, std::vector<T>);

		std::vector<T> predict(std::vector<std::vector<T>>);

		void printCoefficients();
	};

} // namespace slkt

// Include implementation.
#include "linear_regression_impl.hpp"

#endif // SLOWMOKIT_LINEAR_REGRESSION_HEADER_HPP
