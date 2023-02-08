# Logistic Regression

Logistic Regression model using stocastic gradient descent.

LogisticRegression fits a linear model with coefficients $w\  =\  [(w_1, w_2, … , w_p),(w_1, w_2, … , w_p)..]$, where $p$ is number of features and height will be equals to number of classes, to minimize the residual sum of squares between the observed targets in the dataset, and the probabilities predicted by the logistic approximation.

## Parameters

| Name          | Definition                                                                                  | Defaults | Type     |
| ------------- | ------------------------------------------------------------------------------------------- | -------- | ---------|
| Epochs        | Number of times that the learning algorithm will work through the entire training dataset   | 100      | `int`    |
| Learning rate | Determines the step size at each iteration while trying to minimize the loss function       | 0.01     | `double` |

## Attributes

| Name         | Definition                                                | Shape      |
| ------------ | --------------------------------------------------------- | ---------- |
| beta | weights of model  | n_features*output_classes |

## Methods

| Name                            | Definition                                            | Return value      |
| ------------------------------- | ----------------------------------------------------- | ----------------- |
| `softmax(vector<T> x)`          | Computes softmax                                      | `vector<T>`       |
| `crossEntropy(vector<int>y,vector<T>qi)` | actual*predicted value                       | DOUBLE       |
| `EvalL(vector<vector<T>>x,vector<vector<int>>y,vector<vector<T>>beta)`| Computes loss  |      DOUBLE       |
| `logRegSgd(vector<vector<double>>x,vector<vector<int>>y,double alpha,int numEpochs,bool verbose)`| Performs logistic regression  |      `vector<vector<T>>`      |
| `train(vector<vector<T>>x,vector<vector<int>>y,double alpha,int numEpochs,bool verbose)`| Training of model |      void      |
| `predict(std::vector<T> x)`| Gives probability of testing values |      `vector<double> T`      |

## Example

```
LogisticRegression<int> logisticregression;
     std::vector<std::vector<double>> x = {{1,1,1,1},{1,1.87,1.12,0.86},{1,1.09,1.11,0.99},{1,5,4,4.98},{1,4.07,4.76,5.34},     {1,5.65,5.23,4.99},{1,9.98,8.87,8.76},{1,9.83,8.90,8.97}};

     std::vector<std::vector<int>> y = {{1,0,0},{1,0,0},{1,0,0},{0,1,0},{0,1,0},{0,1,0},{0,0,1},{0,0,1}};

     logisticregression.train(x,y,0.0001,2000,false);

     std::vector<double> test{1,1,0.64,0.6};

     std::vector<double> trained = logisticregression.predict(test);

     for(int i=0;i<trained.size();i++){
         std::cout<<trained[i]<<std::endl;
     }

```