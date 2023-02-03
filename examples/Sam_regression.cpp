#include <iostream>
#include <vector>
#include <cmath>

class SVMRegression {
 public:
  SVMRegression(double C, double epsilon, int max_iter) : C_(C), epsilon_(epsilon), max_iter_(max_iter) {}

  void fit(const std::vector<std::vector<double>> &X, const std::vector<double> &y) {
    int n_samples = X.size();
    int n_features = X[0].size();
    alpha_ = std::vector<double>(n_samples, 0.0);
    b_ = 0.0;

    for (int i = 0; i < max_iter_; i++) {
      int num_changed_alphas = 0;
      for (int j = 0; j < n_samples; j++) {
        double prediction = predict(X[j]);
        double error = prediction - y[j];
        if ((error * y[j] < -epsilon_ && alpha_[j] < C_) || (error * y[j] > epsilon_ && alpha_[j] > 0)) {
          int k = select_j(j, n_samples, error);
          double alpha_j = alpha_[j];
          double alpha_k = alpha_[k];
          double y_j = y[j];
          double y_k = y[k];
          double delta = (2.0 * dot(X[j], X[k]) - dot(X[j], X[j]) - dot(X[k], X[k])) / 2.0;
          if (delta >= 0) {
            continue;
          }
          double new_alpha_j = alpha_j - y_j * (error - y_k * (alpha_j - alpha_k)) / delta;
          if (new_alpha_j > C_) {
            new_alpha_j = C_;
          }
          if (new_alpha_j < 0) {
            new_alpha_j = 0;
          }
          double new_alpha_k = alpha_k + y_j * y_k * (alpha_j - new_alpha_j);
          alpha_[j] = new_alpha_j;
          alpha_[k] = new_alpha_k;
          double b1 = b_ - error - y_j * (new_alpha_j - alpha_j) * dot(X[j], X[j]) - y_k * (new_alpha_k - alpha_k) * dot(X[j], X[k]);
          double b2 = b_ - error - y_j * (new_alpha_j - alpha_j) * dot(X[j], X[k]) - y_k * (new_alpha_k - alpha_k) * dot(X[k], X[k]);
          if (0 < new_alpha_j && new_alpha_j < C_) {
            b_ = b
