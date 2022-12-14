#include<bits/stdc++.h>

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
    virtual void fit(std::vector<std::vector<T>> x, std::vector<T> y) = 0;

    /*
    Takes features and predicts target values for trained weights
    @param x features
    @return yPred target variables
    */
    virtual std::vector<T> predict(std::vector<std::vector<T>> x) = 0;
};