// #include "../src/slowmokit/methods/linear_model/ridge_regression.hpp"

// int main()
// {
//   double alpha = 0.01;
//   std::vector<std::vector<double>> x = {
//       {1, 2, 3}, {2, 3, 4}, {3, 4, 5}, {4, 5, 6}};
//   std::vector<double> y = {2, 3, 4, 5};

//   double lambda = 0.1;
//   int epochs = 1000;
//   RidgeRegularization<double> model(alpha);
//   model.fit(x, y, epochs, alpha);
//   model.printCoefficients();
//   std::vector<double> yPred;
//   for (int i = 0; i < x.size(); i++)
//   {
//     yPred.push_back(predict(x[i]));
//   }
//   for (int i = 0; i < y.size(); i++)
//     std::cout << "Actual value: " << y[i] << ", Predicted value: " << yPred[i]
//               << std::endl;

//   return 0;
// }
