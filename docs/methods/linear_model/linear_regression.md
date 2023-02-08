# Linear Regression

Linear Regression model using stocastic gradient descent.

LinearRegression fits a linear model with coefficients w = (w1, …, wp) to minimize the residual sum of squares between the observed targets in the dataset, and the targets predicted by the linear approximation.

## Parameters

| Name          | Definition                                                                                  | Defaults | Type   |
| ------------- | ------------------------------------------------------------------------------------------- | -------- | ------ |
| Epochs        | Number times that the learning algorithm will work through the entire training dataset      | 100      | INT    |
| Learning rate | Determines the step size at each iteration while moving toward a minimum of a loss function | 0.01     | DOUBLE |

## Attributes

| Name         | Definition                                                | Shape      |
| ------------ | --------------------------------------------------------- | ---------- |
| Coefficients | Estimated coefficients for the linear regression problem. | n_features |

## Methods

| Name                            | Definition                                            | Return value      |
| ------------------------------- | ----------------------------------------------------- | ----------------- |
| `fit(vector<T> x, vector<T> y)` | Fit linear model.                                     | void              |
| `predict(vector<T> x)`          | Predict using the linear model.                       | `vector<T> yPred` |
| `printCoefficients()`           | Print coefficient of determination of the prediction. | void              |

## Example

```
LinearRegression<double> model;

std::vector<vector<double>>  x  = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}};

std::vector<double>  y  = {2, 3, 4, 5, 6};



model.fit(x, y);

model.printCoefficients();



std::vector<double>  yPred  =  model.predict(x);

for (int  i  =  0; i  <  y.size(); i++)

cout <<  "Actual value: "  <<  y[i]  <<  ", Predicted value: "  <<  yPred[i]  << endl;

```
