/**
 * @file methods/metrics/accuracy.cpp
 *
 * Implementation of the Accuracy score main program
 */
#include "accuracy.hpp"
template <class T>
double accuracy(const std::vector<T> &pred, const std::vector<T> &trueLabels)
{
    if (pred.size() != trueLabels.size())
    {
        throw std :: domain_error("pred and true_labels must have same size");
    }
    int correct = 0;
    int total = pred.size();
    for (int i = 0; i < total; i++)
    {
        if (pred[i] == trueLabels[i])
        {
            correct++;
        }
    }
    return (double)correct / total;
    
}
