/**
 * @file methods/preprocessing/csv_reader.cpp
 *
 * Implementation of Csv reader
 */

#include "csv_reader.hpp"

template <class T>
std::vector<std::vector<std::string>> readCsv(std::string name, bool index)
{
	std::ifstream file;
	file.open(name);
	std::string output;
	if (index)
	{
		getline(file, output);
	}
	getline(file, output);
	bool duble = true;
	std::vector<int> isDouble;
	std::string current = "";
	for (int i = 0; i < output.size(); i++)
	{
		if (output[i] == ',')
		{
			if (duble and current.size() > 0)
			{
				isDouble.push_back(1);
			}
			else
			{
				isDouble.push_back(0);
			}
			duble = true;
			current = "";
		}
		else
		{
			current += output[i];
			if ((output[i] >= '0' and output[i] <= '9') or output[i] == '.')
			{
				continue;
			}
			else
			{
				duble = false;
			}
		}
	}
	file.close();

	// Storing all values as string with their data type at top of them
	std::vector<std::vector<std::string>> csvFile;
	std::vector<std::string> first(isDouble.size());
	for (int i = 0; i < isDouble.size(); i++)
	{
		first[i] = std::to_string(isDouble[i]);
	}
	csvFile.push_back(first);
	file.open(name);

	while (getline(file, output))
	{
		first.clear();
		current = "";
		for (int i = 0; i < output.size(); i++)
		{
			if (output[i] == ',')
			{
				first.push_back(current);
				current = "";
			}
			else
			{
				current += output[i];
			}
		}
		csvFile.push_back(first);
	}

	return csvFile;
}