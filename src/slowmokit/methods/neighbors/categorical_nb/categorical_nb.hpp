/**
 * @file methods/neighbors/categorical_nb/categorical_naive_bayes.hpp
 *
 * The header file including the Categorical Naive Bayes algorithm
 */

#ifndef SLOWMOKIT_CATEGORICAL_NB_HPP
#define SLOWMOKIT_CATEGORICAL_NB_HPP

#include "../../../core.hpp"

template<class T> class categoricalNB{
public:
    /**
    * @brief Fit predict at same time
    *
    * @param xTrain all training 2-d feature x values
    * @param yTrain all training 1-d string y values
    * @param xTest testing values
    * @return class label predicted for test case
    */
    std::string fitPredict(std::vector<std::vector<T>> xTrain, std::vector<std::string> yTrain,std::vector<T> xTest);
};

#endif //SLOWMOKIT_CATEGORICAL_NB_HPP
