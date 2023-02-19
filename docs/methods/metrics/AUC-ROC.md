# AUC-ROC

AUC - ROC curve is a performance measurement for the classification problems at various threshold settings. ROC is a probability curve and AUC represents the degree or measure of separability. It tells how much the model is capable of distinguishing between classes. Higher the AUC, the better the model is at predicting 0 classes as 0 and 1 classes as 1. By analogy, the Higher the AUC, the better the model is at distinguishing between patients with the disease and no disease.

An ROC curve (receiver operating characteristic curve) is a graph showing the performance of a classification model at all classification thresholds. This curve plots two parameters:

-True Positive Rate
-False Positive Rate


True Positive Rate (TPR) is a synonym for recall and is therefore defined as follows:

TPR = TP/( TP + FN )


False Positive Rate (FPR) is defined as follows:

FPR = FP/( FP + TN )

## Parameters

| Name          | Definition                                                                                  | Type            |
| ------------- | ------------------------------------------------------------------------------------------- | ----------------|
| fpr           | Takes a vector of false positive rates                                                      | `int,double`    |
| tpr           | Takes a vector of true positive rates                                                       | `int,double`    |



## Methods

| Name                                           | Definition                                            | Return value         |
| -----------------------------------------------| ----------------------------------------------------- | -------------------  |
| `plotAUCROC(vector<T> fpr, vector<T> tpr)`     | To evaluate a model                                   |`map<double,double>'  |


## Example

To plot an AUC-ROC curve in C++, you can use a plotting library like Gnuplot. Gnuplot is a portable command-line driven graphing utility that supports various plotting types, including curves, surfaces, and histograms.

Here is an example of how to plot an AUC-ROC curve using Gnuplot in C++:

```cpp
#include <vector>
#include <gnuplot_i.hpp> // Gnuplot header file

// Function to plot the AUC-ROC curve
void plotAUCROC(const std::vector<double>& fpr, const std::vector<double>& tpr) {
    // Initialize Gnuplot object
    Gnuplot plot;

    // Set plot title and axis labels
    plot.set_title("AUC-ROC Curve");
    plot.set_xlabel("False Positive Rate");
    plot.set_ylabel("True Positive Rate");

    // Plot the AUC-ROC curve
    plot.plot_xy(fpr, tpr, "AUC-ROC");

    // Show the plot
    plot.show();
}

int main() {
    // Example data for false positive rate and true positive rate
    std::vector<double> fpr = {0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0};
    std::vector<double> tpr = {0.0, 0.2, 0.3, 0.5, 0.6, 0.7, 0.8, 0.9, 0.95, 1.0, 1.0};

    // Plot the AUC-ROC curve
    plotAUCROC(fpr, tpr);

    return 0;
}




```

