#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Model
{
public:
    /*
    Takes features and target as value and trains model using those values
    @param x features
    @param y target variables
    @throws Invalid input exception
    */
    virtual void fit(vector<vector<T>> x, vector<T> y) = 0;

    /*
    Takes features and predicts target values for trained weights
    @param x features
    @return yPred target variables
    */
    virtual vector<T> predict(vector<vector<T>> x) = 0;
};