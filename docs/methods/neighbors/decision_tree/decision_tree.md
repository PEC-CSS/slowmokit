# Decision Tree

Decision Tree model.

Decision Tree forms the tree based on the best information gain we received at each node. The tree formed later use to predict the output values for test data.


## Attributes

| Name             | Definition                                                   | Shape      |
| ------------     | ---------------------------------------------------------    | ---------- |
| entropy | Entropy of the y values left                                          | 1          |
| max depth       | Max depth of the decision tree                                | 1          |
| max depth       | Max depth of the decision tree                                | 1          |
| min Samples leaf | Minimum samples that should be there to form further nodes of branch                                | 1          |
| target       | Output class                                | 1          |
| max features       | Max features that should be considered to form further branches                               | 1          |
| features       | All the features/columns in data                                | n_features         |
| fkey       | Column number that will be considered to form next node                                | 1          |
| fval       | Double splitting value                               | 1          |
| left       | Left node of decision tree                               | 1          |
| right       | Right node of decision tree                                | 1          |

## Methods

| Name                                    | Definition                                            | Return value      |
| -------------------------------         | ----------------------------------------------------- | ----------------- |
| `entropy(vector<double>)`           | Compute entropy                                       | double            |
| `divideData(vector<vector<double>>,int,int)` | Divide the data after finding best Info gain     | `vector<vector<vector<double>>>`|
| `infoGain(vector<vector<double>>,int,int)` | Computes info gain                  | double    |
| `train(vector<vector<double>>)` | Train the model on training values                  | void    |
| `predict(vector<double>)` | Predict the output for testing value                  | int    |

## Example

```
std::vector<std::vector<double>> x_data{{0,23.76,3,76.56,1},{1,12.76,2,87.45,0},{1,21.86,1,79.98,1},{0,32.64,1,76.87,1},{0,22.76,3,89.90,0},{1,28.64,0,73.87,1},{0,12.87,3,82.86,0}};
DecisionTree<double> dt = new DecisionTree(9,0,4);
dt->train(x_data);
std::vector<double> test{1,38.19,2,81.65};
std::cout<<dt->predict(test);

```
