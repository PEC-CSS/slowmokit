#include "one_hot_encoder.hpp"

template<class T>
// Function to one hot encode 
std::vector<std::vector<int>> oneHotEncoder(const std::vector<T> &data, int nClasses) {
// Created a map to store the mapping of each integer in the data to a different index
  std::map<T, int> classMapping;
  int classIndex = 0;
  for (const T &value : data) {
    if (classMapping.count(value) == 0) {
      classMapping[value] = classIndex++;
    }
  }
 // Vector to store the one hot encoded data
  std::vector<std::vector<int>> oneHotEncodedData(data.size(), std::vector<int>(nClasses, 0));
//created a one hot encoded representation for each value
  for (int i = 0; i < data.size(); i++) {
    oneHotEncodedData[i][classMapping[data[i]]] = 1;
  }
 // To Return the one hot encoded data
  return oneHotEncodedData;
}

