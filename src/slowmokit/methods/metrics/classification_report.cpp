/**
 * @file methods/metrics/classification_report.hpp
 *
 * Easy include to show the classification report of data
 */

#include "classification_report.hpp"
template <class T>

ClassificationReport<T>::ClassificationReport(std::vector<T> &trueValue, std::vector<T> &predictedValue)
{
    this->trueValue = trueValue;
    this->predictedValue = predictedValue;
}

template <class T>
void ClassificationReport<T>::confusionMatrix(std::vector<T> &trueValue, std::vector<T> &predictedValue)
{
    int n = trueValue.size();

    for (int i = 0; i < n; i++)
    {
        classes[trueValue[i]]++;
        if (trueValue[i] == predictedValue[i])
        {
            truePositive[trueValue[i]]++;
        }
        if (trueValue[i] != predictedValue[i])
        {
            falseNegative[trueValue[i]]++;
            falsePositive[predictedValue[i]]++;
        }
    }
    // For True Negative, had to do it separately :crycatok:
    for (auto it : classes)
    {
        int classNumber = it.first;
        for (int i = 0; i < n; i++)
        {
            if (trueValue[i] != classNumber && predictedValue[i] != classNumber)
            {
                trueNegative[classNumber]++;
            }
        }
    }
}

template <class T>
std::map<T, double> ClassificationReport<T>::precision()
{
    // True Positive / (True Positive + False Positive)
    std::map<T, double> Precision;
    // std::cout << "class size"<<classes.size() << std::endl;
    for (auto it : classes)
    {
        int classNumber = it.first;
        // std::cout << classNumber << std::endl;
        Precision[classNumber] = (double)(truePositive[classNumber] / (double)(truePositive[classNumber] + falsePositive[classNumber]));

        // Trick to make all numbers upto 2 decimal place
        double x = Precision[classNumber];
        float value = (int)(x * 100 + .5);
        Precision[classNumber] = (float)value / 100;
    }
    return Precision;
}

template <class T>
std::map<T, double> ClassificationReport<T>::recall()
{
    // True Positive / (True Positive + False Negative)
    std::map<T, double> Recall;
    for (auto it : classes)
    {
        int classNumber = it.first;
        Recall[classNumber] = (double)((double)truePositive[classNumber] / ((double)truePositive[classNumber] + (double)falseNegative[classNumber]));
        double x = Recall[classNumber];
        float value = (int)(x * 100 + .5);
        Recall[classNumber] = (float)value / 100;
    }
    return Recall;
}

template <class T>
std::map<T, double> ClassificationReport<T>::f1_score()
{
    // 2 * Precision * Recall / (Precision + Recall)
    std::map<T, double> Precision, Recall;
    Precision = precision();
    Recall = recall();
    std::map<T, double> F1_Score;
    for (auto it : classes)
    {
        int classNumber = it.first;
        if (Precision[classNumber] == 0 || Recall[classNumber] == 0)
        {
            F1_Score[classNumber] = 0;
        }
        else
        {
            F1_Score[classNumber] = (2 * (double)Precision[classNumber] * (double)Recall[classNumber]) / ((double)Precision[classNumber] + (double)Recall[classNumber]);
            
            double x = F1_Score[classNumber];
            float value = (int)(x * 100 + .5);
            F1_Score[classNumber] = (float)value / 100;
        }
    }
    return F1_Score;
}

template <class T>
std::map<T, double> ClassificationReport<T>::accuracy()
{
    // (True Positive  + True Negative)/ (True Positive + False Positive + False Negative + True Negative)
    std::map<T, double> Accuracy;
    for (auto it : classes)
    {
        int classNumber = it.first;
        Accuracy[classNumber] = (double)(((double)truePositive[classNumber] + (double)trueNegative[classNumber]) / ((double)truePositive[classNumber] + (double)falseNegative[classNumber] + (double)falsePositive[classNumber] + (double)trueNegative[classNumber]));
    }
    return Accuracy;
}

template <class T>
void ClassificationReport<T>::PrintReport()
{
    std::cout << "Class-No. Precision Accuracy  Recall   F1_Score\n";
    std::map<int, double> Precision = precision();
    std::map<int, double> Accuracy = accuracy();
    std::map<int, double> Recall = recall();
    std::map<int, double> F1_score = f1_score();
    for (auto classNumber : classes)
    {
        std::cout << std::setw(4) << classNumber.first << std::setw(10) << Precision[classNumber.first] << std::setw(10) << Accuracy[classNumber.first] << std::setw(11) << Recall[classNumber.first] << std::setw(10) << F1_score[classNumber.first] << std::endl;
    }
}

int main()
{
    std::vector<int> trueValue = {0, 1, 2, 2, 2};
    std::vector<int> predictedValue = {0, 0, 2, 2, 1};
    ClassificationReport Class(trueValue, predictedValue);
    Class.confusionMatrix(trueValue, predictedValue);
    Class.PrintReport();
}