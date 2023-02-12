/**
 * @file ducks/train_test_split/train_test_split.cpp
 *
 * Implementation of the train_test_split function
 */

#include "train_test_split.hpp"
#include "../../ducks/random/random.hpp"

namespace detail
{
	// To allow ADL with custom begin/end
	using std::begin;
	using std::end;

	template <typename T>
	auto isIterableImpl(int)
	    -> decltype(begin(std::declval<T &>()) !=
	                    end(std::declval<T &>()), // begin/end and operator !=
	                void(),                       // Handle evil operator ,
	                ++std::declval<decltype(begin(
	                    std::declval<T &>())) &>(),    // operator ++
	                void(*begin(std::declval<T &>())), // operator*
	                std::true_type {});

	template <typename T>
	std::false_type isIterableImpl(...);

} // namespace detail

template <typename T>
using is_iterable = decltype(detail::isIterableImpl<T>(0));

template <typename T, typename G>
using train_test_quadruple =
    std::tuple<std::vector<T>, std::vector<G>, std::vector<T>, std::vector<G>>;

template <class T, class G>

train_test_quadruple<T, G> trainTestSplit(const std::vector<T> &X,
                                          const std::vector<G> &y,
                                          double testSize, double trainSize)
{
	if (std::size(X) != std::size(y))
		throw std::invalid_argument("size of both iterables must be equal.");

	train_test_quadruple<T, G> res;
	auto &[xTrain, xTest, yTrain, yTest] = res;

	std::vector<std::pair<T, G>> input;
	for (int i = 0; i < std::size(X); i++)
		input.emplace_back(X[i], y[i]);

	std::mt19937 rng(seed);
	std::shuffle(std::begin(input), std::end(input), rng);

	int n = std::size(input);
	int trainDataSize = n * trainSize;
	int testDataSize = n - trainDataSize;

	if (trainDataSize == 0 || testDataSize <= 0)
		throw std::invalid_argument("Dataset too small");

	auto xData = std::vector<std::pair<T, G>>(
	    std::begin(input), std::begin(input) + trainDataSize);
	auto yData = std::vector<std::pair<T, G>>(std::begin(input) + trainDataSize,
	                                          std::end(input));

	for (auto &[train, test] : xData)
	{
		xTrain.emplace_back(train);
		xTest.emplace_back(test);
	}

	for (auto &[train, test] : yData)
	{
		yTrain.emplace_back(train);
		yTest.emplace_back(test);
	}

	return res;
}