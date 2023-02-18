# Ridge Regularization

It adds L2 as the penalty.

L2 is the sum of the square of the magnitude of beta coefficients.

## Parameters

| Name          | Definition                                                                                  | Defaults | Type     |
| ------------- | ------------------------------------------------------------------------------------------- | -------- | ---------|
| lambda        | Constant that multiplies the L1 term, controlling regularization strength                   | 0.01     | `double` |


## Attributes

| Name         | Definition                                                | Shape      |
| ------------ | --------------------------------------------------------- | ---------- |
| Coefficients | Estimated coefficients for the ridge regularization       | n_features |

## Methods

| Name                            | Definition                                                               | Return value      |
| ------------------------------- | -----------------------------------------------------                    | ----------------- |
| `lossFunction(vector<T> x, double y)` |regularize loss function                                 | `double`          |
| `gradient(vector<T> x,double y)` | Find gradient                                                | `vector<double>`  |
| `gradientDescent(vector<vector<T>> x, vector<T> y, double alpha,int epochs)` | gradient optimization algorithm        | `void`            |
| `fit(vector<vector<T>> x, vector<T> y,int epochs,double alpha)` | Fit linear model                                            | `vector<double>`  |
| `predict(vector<T> x)`          | Predict using the linear model                                           | `double`          |
| `printCoefficients()`           | Print coefficient of determination of the prediction                     | `void`            |

## Example

```cpp
double alpha = 0.01;
std::vector<std::vector<double>> x = {{1, 2, 3}, {2, 3, 4}, {3, 4, 5}, {4, 5, 6}};
std::vector<double> y = {2, 3, 4, 5};
double lambda = 0.1;
int epochs = 1000;
RidgeRegularization<double> model(alpha);
model.fit(x, y, epochs, alpha);
model.printCoefficients();
std::vector<double> yPred;
for (int i = 0; i < x.size(); i++)
{
   yPred.push_back(predict(x[i]));
}
for (int i = 0; i < y.size(); i++)
  std::cout << "Actual value: " << y[i] << ", Predicted value: " << yPred[i] << std::endl;

```
