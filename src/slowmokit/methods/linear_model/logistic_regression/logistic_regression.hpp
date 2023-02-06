/**
 * @file methods/linear_model/logistic_regression/logistic_regression.hpp
 *
 * The header file including the logistic regression algorithm
 */

#ifndef SLOWMOKIT_LOGISTIC_REGRESSION_HPP
#define SLOWMOKIT_LOGISTIC_REGRESSION_HPP

#include "../../../core.hpp"

template<class T>
class LogisticRegression{
private:
    std::vector<std::vector<T>> beta;   // Initializing beta i.e weights -> (output_classes * numbers_of_features)

    std::vector<double> softmax(std::vector<T> x);

    double crossEntropy(std::vector<int> y,std::vector<T> qi);

    double EvalL(std::vector<std::vector<T>> x,std::vector<std::vector<int>>y,std::vector<std::vector<T>> beta);

    std::vector<std::vector<double>> logRegSgd(std::vector<std::vector<double>> x,std::vector<std::vector<int>> y,double alpha,int numEpochs,bool verbose);

public:

    void train(std::vector<std::vector<T>> x,std::vector<std::vector<int>> y,double alpha,int numEpochs,bool verbose);
    
    std::vector<double> predict(std::vector<T> x);
};

#endif  //SLOWMOKIT_LOGISTIC_REGRESSION_HPP