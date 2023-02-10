/**
 * @file methods/preprocessing/normalization.CPP
 *
 * Implementation of the Accuracy score main program
 */
#include "normalization.hpp"
template<class T> void normalize(std::vector<T> &values)
{
	T minimum = *min_element(values.begin(), values.end());
	T maximum = *max_element(values.begin(), values.end());

	int n = values.size();

	if (minimum == maximum)
	{
		for (int i = 0; i < n; i++)
		{
			values[i] = 1;
		}
		std::cerr << "Warning: All the values in the given column are equal"
		          << std::endl;
		return;
	}
	for (int i = 0; i < n; i++)
	{
		values[i] = ((values[i] - minimum) / (maximum - minimum));
	}
}
