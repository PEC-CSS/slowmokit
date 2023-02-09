# KNN

KNN model using euclidean/manhattan distance.

KNN fits the inputs that is store them and when we provide a testing value it computes manhattan/euclidean distance and accordingly gives the predicted class output .

## Parameters

| Name          | Definition                                                                                  | Defaults | Type   |
| ------------- | ------------------------------------------------------------------------------------------- | -------- | ------ |
| classNums        | Number of classes in training set   | 1      | INT    |
| k | Number of points to be considered to compute class output      | 5     | INT |


## Methods

| Name                            | Definition                                            | Return value      |
| ------------------------------- | ----------------------------------------------------- | ----------------- |
| `distance(vector<T>x1,vector<T>x2)` | Computes distance b/w points                                     | DOUBLE            |
| `fit(vector<vector<T>> x,vector<int> y,int classNums)`          | Fit the model.                       | void |
| `predict(vector<T> test,int k,string distType)`           | Predict the class output for testing value. | void              |

## Example

```
// std::vector<std::vector<double>> x{{4.23,24.4,34.24},{2.23,23.43,34.23}}

std::vector<int> y{0,1};

int k=2;

int classNums=2;

KNN<double> knn;

knn.fit(x,y,k,classNums);

std::vector<double> xTest{23.23,34.42,4.23};

std::cout<<knn.predict(xTest)<<endl;

```