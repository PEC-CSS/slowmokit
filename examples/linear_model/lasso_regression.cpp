// #include "../src/slowmokit/methods/linear_model/lasso_regression.hpp"

// int main()
// {
//   std::vector<std::vector<double>> x = {
//       {1.0, 2.0, 3.0}, {2.0, 3.0, 4.0}, {3.0, 4.0, 5.0}};
//   std::vector<double> y = {1.0, 2.0, 3.0};
//   double alpha = 0.01;
//   double lambda = 0.1;
//   int epochs = 100;

//   LassoRegularization<double> model(alpha);
//   model.fit(x, y, epochs, alpha);
//   model.printCoefficients();

//   std::vector<double> yPred = model.predict(x);
//   for (int i = 0; i < y.size(); i++)
//     std::cout << "Actual value: " << y[i] << ", Predicted value: " << yPred[i]
//               << std::endl;

//   return 0;
// }