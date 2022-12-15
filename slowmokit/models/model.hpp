/**
 * @file model.hpp
 *
 * This contains the basic class of a model, which contains two standard functions i.e, fit and predict.
 * Inherit this class to create some model.
 */

#ifndef SLOWMOKIT_MODEL_HPP
#define SLOWMOKIT_MODEL_HPP

#include "../core.hpp"

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
    virtual void fit(std::vector<std::vector<T> > x, std::vector<T> y) = 0;

    /*
    Takes features and predicts target values for trained weights
    @param x features
    @return yPred target variables
    */
    virtual std::vector<T> predict(std::vector<std::vector<T> > x) = 0;
};

#endif //SLOWMOKIT_MODEL_HPP
