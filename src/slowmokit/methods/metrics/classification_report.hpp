/**
 * @file methods/metrics/classification_report.hpp
 *
 * Easy include to show the classification report of data
 */

#ifndef SLOWMOKIT_CLASSIFICATION_REPORT_HPP
#define SLOWMOKIT_CLASSIFICATION_REPORT_HPP
#include "../../core.hpp"

template <class T>
class ClassificationReport
{
private:
    std::vector<T> trueValue;
    std::vector<T> predictedValue;
    std::map<T, T> classes, truePositive, falsePositive, trueNegative, falseNegative;

public:
    ClassificationReport(std::vector<T> &x, std::vector<T> &y);

    void confusionMatrix(std::vector<T> &, std::vector<T> &);

    std::map<T, double> precision();

    std::map<T, double> recall();

    std::map<T, double> f1_score();

    std::map<T, double> accuracy();

    void PrintReport();
};

#endif // SLOWMOKIT_CLASSIFICATION_REPORT_HPP