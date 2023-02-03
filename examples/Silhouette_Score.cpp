#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

double euclidean_distance(const std::vector<double> &a, const std::vector<double> &b) {
  double sum = 0.0;
  for (int i = 0; i < a.size(); i++) {
    sum += (a[i] - b[i]) * (a[i] - b[i]);
  }
  return sqrt(sum);
}

double average_distance(const std::vector<std::vector<double>> &data, int cluster, const std::vector<int> &labels) {
  double sum = 0.0;
  int count = 0;
  for (int i = 0; i < data.size(); i++) {
    if (labels[i] == cluster) {
      for (int j = 0; j < data.size(); j++) {
        if (labels[j] == cluster && i != j) {
          sum += euclidean_distance(data[i], data[j]);
          count++;
        }
      }
    }
  }
  return sum / count;
}

double silhouette_score(const std::vector<std::vector<double>> &data, const std::vector<int> &labels) {
  double score = 0.0;
  for (int i = 0; i < data.size(); i++) {
    int current_cluster = labels[i];
    double a = average_distance(data, current_cluster, labels);
    double b = std::numeric_limits<double>::max();
    for (int j = 0; j < labels.size(); j++) {
      if (labels[j] != current_cluster) {
        double current_b = average_distance(data, labels[j], labels);
        b = std::min(b, current_b);
      }
    }
    score += (b - a) / std::max(a, b);
  }
  return score / data.size();
}

int main() {
  std::vector<std::vector<double>> data = {{1, 2, 3}, {2, 3, 4}, {3, 4, 5}, {4, 5, 6}};
  std::vector<int> labels = {0, 0, 1, 1};
  std::cout << "Silhouette Score: " << silhouette_score(data, labels) << std::endl;
  return 0;
}
