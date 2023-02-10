# Gaussian Naive Bayes

Gaussian Naive Bayes model.

Gaussian Naive Bayes computes likelihood/conditional Prob by.
Conditional probabilty  P(x=f1 / y=class) = __________1____________ * e^(-_____(feature-mean)^2_____)
                                            ((2*pi*variance^2)^(1/2))           (2 * variance^2)

Also computes the prior probability and finally prior*likelihood gives the probabilty of class according to which output class is predicted.


## Attributes

| Name             | Definition                                                   | Shape      |
| ------------     | ---------------------------------------------------------    | ---------- |
| Conditional Prob | Conditional probability of each feature value for each class | 1          |

## Methods

| Name                                    | Definition                                            | Return value      |
| -------------------------------         | ----------------------------------------------------- | ----------------- |
| `conditionalProb(int mean,int variance,int feature)` |Conditional Probability.            | double            |
| `fitPredict(vector<vector<T>>xTrain,vector<T>yTrain,vector<T>xTest,vector<int> classes)`        | fit and predict the training and testing values | int    |

## Example

```
std::vector<std::vector<double>> x_train{{6,180,12},{5.92,190,11},{5.58,170,12},{5.92,165,10},{5,100,6},{5.5,150,8},{5.42,130,7},{5.75,150,9}};

   std::vector<int> y_train{0,0,0,0,1,1,1,1};

   std::vector<double> x_test{6,130,8};

   std::vector<int> classes{0,1};

   GaussianNB<double> gaussian;

   std::cout<<gaussian.fitPredict(x_train,y_train,x_test,classes)std::<<endl;

```
