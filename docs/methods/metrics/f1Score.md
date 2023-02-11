# F1 Score

The F1-score combines the precision and recall of a classifier into a single metric by taking their harmonic mean. It is primarily used to compare the performance of two classifiers.


## Parameters

| Name          | Definition                                                                                  | Type            |
| ------------- | ------------------------------------------------------------------------------------------- | ----------------|
| Pred          | Takes a vector of predicted values                                                          | `int,double`    |
| Actual        | Takes a vector of actual values                                                             | `int,double`    |


## Methods

| Name                                           | Definition                                            | Return value      |
| -----------------------------------------------| ----------------------------------------------------- | ----------------- |
| `f1Score(vector<T> &x, vector<T> &y)`          | To find the f1 Score                                 |  `map<T,double>`  |

## Example

```cpp
std::vector<int> pred = {0, 1, 2, 1, 0, 2, 1, 0, 1, 2};
std::vector<int> actual = {0, 0, 2, 1, 0, 2, 1, 0, 1, 2};
std::map<int, double> f1ScoreEg = f1Score(pred, actual);
for(int i = 0; i < f1ScoreEg.size(); i++){
     std::cout << "Class " << i << " F1_Score: " << f1ScoreEg[i] << std::endl;
}

```
<img width="298" alt="Screenshot 2023-02-10 at 10 14 46 PM" src="https://user-images.githubusercontent.com/89138051/218148120-b64a25b8-8daa-49cc-a1f3-2bfe316622af.png">
