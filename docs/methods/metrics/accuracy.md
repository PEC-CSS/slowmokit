# Accuracy

The Accuracy score (or just Accuracy) is a Classification metric featuring a fraction of the predictions that a model got right.The Accuracy score is calculated by dividing the number of correct predictions by the total prediction number.

## Parameters

| Name          | Definition                                                                                  | Type            |
| ------------- | ------------------------------------------------------------------------------------------- | ----------------|
| Pred          | Takes a vector of predicted values                                                          | `int,double`    |
| Actual        | Takes a vector of actual values                                                             | `int,double`    |


## Methods

| Name                                           | Definition                                            | Return value      |
| -----------------------------------------------| ----------------------------------------------------- | ----------------- |
| `accuracy(vector<T> x, vector<T> y)`           | To find the accuracy score                            |    `double`       |

## Example

```cpp
std::vector<int> pred = {1, 0, 1, 1, 0, 1};
std::vector<int> trueLabels = {1, 0, 0, 1, 0, 1};
double acc = accuracy(pred, trueLabels);
std::cout << "Accuracy: " << acc << std::endl;

```
