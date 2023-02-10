/**
 * @file methods/preprocessing/one_hot_encoder.cpp
 *
 * Implementation of one hot encoder
 */

#include "one_hot_encoder.hpp"
template<class T>
std::vector<std::vector<int>> oneHotEncoder(const std::vector<T> &data,
                                            int nClasses)
{

	std::map<T, int> classMapping;
	int classIndex = 0;
	for (const T &value : data)
	{
		if (classMapping.count(value) == 0)
		{
			classMapping[value] = classIndex++;
		}
	}
	std::vector<std::vector<int>> oneHotEncodedData(
	    data.size(), std::vector<int>(nClasses, 0));

	for (int i = 0; i < data.size(); i++)
	{
		oneHotEncodedData[i][classMapping[data[i]]] = 1;
	}
	return oneHotEncodedData;
}
