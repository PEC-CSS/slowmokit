# Linear Regression

Bernoulli Naive Bayes model.

Bernoulli Naive Bayes computes likelihood/conditional Prob as log(y)*x + (1-x)(1-log(y)). Also computes the prior probability and finally prior*likelihood gives the probabilty of class according to which output class is predicted.


## Attributes

| Name             | Definition                                                   | Shape      |
| ------------     | ---------------------------------------------------------    | ---------- |
| Conditional Prob | Conditional probability of each feature value for each class | n_features |
| Prior Prob       | Prior probability of each feature value for each class       | 1          |

## Methods

| Name                                    | Definition                                            | Return value      |
| -------------------------------         | ----------------------------------------------------- | ----------------- |
| `priorProb(vector<T> yTrain,int label)` | Compute prior prob.                                   | double            |
| `conditionalProb(vector<vector<T>>,vector<T>,int,int,int)` |Conditional Probability.            | `vector<T> yPred` |
| `fitPredict(vector<vector<T>>,vector<T>,vector<T>)`        | fit and predict the traing and testing values | void      |

## Example

```
std::vector<std::vector<int>> xTrain{{0,0,0},{1,0,0},{1,0,1},{1,0,0},{0,1,1},{1,0,0},{1,1,0},{0,1,1},{1,0,1},{1,1,1}};

std::vector<int> yTrain{0,0,1,1,0,0,1,1,1,0};

std::vector<int> xTest{1,0,0};

BernoulliNB<int> bernoulli;

std::cout<< bernoulli.fitPredict(xTrain,yTrain,xTest) << endl;

```
