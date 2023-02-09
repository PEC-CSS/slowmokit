# Classification Report

A Classification report is used to measure the quality of predictions from a classification algorithm.

## Parameters

| Name             | Definition                                                                              | Type |
| -----------------| --------------------------------------------------------------------------------------- | ---- |
| True Values      | It is vector of the actual values                                                       |   `T`|
| Predicted Values | It is vector of the predicted values                                                    |   `T`|


## Methods

| Name                            | Definition                                            | Return value      |
| ------------------------------- | ----------------------------------------------------- | ----------------- |
| `confusionMatrix(vector<T> &x, vector<T> &y)`| To Calculate TP, FP, TN, FN             | `void`            |
| `precision()`                   | To find the Precision Value                           | `map<T, double>`  |
| `recall()`                      | To find the Recall Value                              | `map<T, double>`  |
| `accuracy()`                    | To find the Accuracy Value                            | `map<T, double>`  |
| `f1Score()`                     | To find the F1-Score Value                            | `map<T, double>`  |
| `printReport()`                 | To Print the Classification Report                    |  `void`           |


## Example

```cpp
     std::vector<int> trueValue = {0, 1, 2, 2, 2};
     std::vector<int> predictedValue = {0, 0, 2, 2, 1};
     ClassificationReport Class(trueValue, predictedValue);
     Class.confusionMatrix(trueValue, predictedValue);
     Class.printReport();
```
