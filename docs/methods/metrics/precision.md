# Precision

The precision is calculated as the ratio between the number of Positive samples correctly classified to the total number of samples classified as Positive (either correctly or incorrectly). The precision measures the model's accuracy in classifying a sample as positive.
The precision reflects how reliable the model is in classifying samples as Positive.

## Parameters

| Name          | Definition                                                                                  | Type            |
| ------------- | ------------------------------------------------------------------------------------------- | ----------------|
| Pred          | Takes a vector of predicted values                                                          | `int,double`    |
| Actual        | Takes a vector of actual values                                                             | `int,double`    |


## Methods

| Name                                           | Definition                                            | Return value      |
| -----------------------------------------------| ----------------------------------------------------- | ----------------- |
| `precision(vector<T> x, vector<T> y)`          | To find the precision                                 |  `map<T,double>'  |

## Example

```cpp
std::vector<int> pred = {0, 1, 2, 1, 0, 2, 1, 0, 1, 2};
std::vector<int> actual = {0, 0, 2, 1, 0, 2, 1, 0, 1, 2};
std::map<int, double> precisionValue = precision(pred, actual);
for(int i = 0; i < precisionValue.size(); i++){
  std::cout << "Class " << i << " precision: " << precisionValue[i] << std::endl; 

```
