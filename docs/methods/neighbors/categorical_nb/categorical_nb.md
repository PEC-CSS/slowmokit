# Categorical Naive Bayes

Categorical Naive Bayes model.

Categorical Naive Bayes computes likelihood by : occurences of instance in current label divided by total occurences of instance

It computes the prior probability by : occurence of current class divided by size of training array

And finally prior*likelihood gives the probabilty of class according to which output class is predicted.


## Parameters

| Name   | Definition                               | Type               |
|--------|------------------------------------------|--------------------|
| `xTrain` | The training set containing the features | `vector<vector<T>>` |
| `yTrain` | The set containing the class correspoding to respective xTrain instance | `vector<string`|
| `xTest` | The sample set , whose class will be predicted | `vector<T>`|

## Methods

| Name                                    | Definition                                            | Return value |
| -------------------------------         | ----------------------------------------------------- |--------------|
| `fitPredict(vector<vector<T>>xTrain,vector<T>yTrain,vector<T>xTest)`        | fit and predict the training and testing values | `string`      |

## Example

```
    std::vector <std::vector<std::string>> xTrain = {{"fifa", "yes", "no",  "no"},
                                                     {"fifa", "no",  "yes", "no"},
                                                     {"fifa", "no",  "no",  "yes"},
                                                     {"cc",   "no",  "no",  "yes"},
                                                     {"fifa", "yes", "yes", "yes"},
                                                     {"cc",   "yes", "yes", "yes"},
                                                     {"cc",   "no",  "no",  "yes"},
                                                     {"cc",   "yes", "no",  "no"}};
    std::vector <std::string> yTrain = {"m", "m", "m", "m", "f", "f", "f", "f"};
    std::vector <std::string> xTest = {"fifa", "no", "yes", "yes"};
    categoricalNB<std::string> classifier;
    std::cout << classifier.fitPredict(xTrain, yTrain, xTest);
```
