#include "src/slowmokit/one_hot_encoder.hpp"

#include <map>

// Function to one hot encode a vector of integers
std::vector<std::vector<int>> one_hot_encoder(const std::vector<int> &data, int n_classes) {
  // Created a map to store the mapping of each integer in the data to a different index
  std::map<int, int> class_mapping;
  int class_index = 0;
  // added each integer to class mapping
  for (int value : data) {
    if (class_mapping.count(value) == 0) {
      class_mapping[value] = class_index++;
    }
  }

  // Vector to store the one hot encoded data
  std::vector<std::vector<int>> one_hot_encoded_data;
  //created a one hot encoded representation for each value
  for (int value : data) {
    // Created a one hot encoded vector for each value in the data
    std::vector<int> one_hot_encoded_row(n_classes, 0);
    one_hot_encoded_row[class_mapping[value]] = 1;
    one_hot_encoded_data.push_back(one_hot_encoded_row);
  }

  // To Return the one hot encoded data
  return one_hot_encoded_data;
}
