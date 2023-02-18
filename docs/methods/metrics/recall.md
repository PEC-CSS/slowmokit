# Recall

The recall is calculated as the ratio between the number of Positive samples correctly classified as Positive to the total number of Positive samples. The recall measures the model's ability to detect Positive samples. The higher the recall, the more positive samples detected.

## Parameters

| Name          | Definition                                                                                  | Type            |
| ------------- | ------------------------------------------------------------------------------------------- | ----------------|
| Pred          | Takes a vector of predicted values                                                          | `int,double`    |
| Actual        | Takes a vector of actual values                                                             | `int,double`    |


## Methods

| Name                                           | Definition                                            | Return value      |
| -----------------------------------------------| ----------------------------------------------------- | ----------------- |
| `recall(vector<T> x, vector<T> y)`             | To find the recall value                              |  `map<T,double>'  |

## Example

```cpp
std::vector<int> pred = {0, 1, 2, 1, 0, 2, 1, 0, 1, 2};
std::vector<int> actual = {0, 0, 2, 1, 0, 2, 1, 0, 1, 2};
std::map<int, double> precisionValue = precision(pred, actual);
std::vector<int> pred = {0, 1, 2, 1, 0, 2, 1, 0, 1, 2};
std::vector<int> actual = {0, 0, 2, 1, 0, 2, 1, 0, 1, 2};
std::map<int, double> RecallValue = recall(pred, actual);
for (int i = 0; i < RecallValue.size(); i++)
{
  std::cout << "Class " << i << " recall: " << RecallValue[i] << std::endl;
}

```
