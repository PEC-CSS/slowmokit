// #include "../src/slowmokit/methods/metrics/classification_report.hpp"

// int main()
// {
//     std::vector<int> trueValue = {0, 1, 2, 2, 2};
//     std::vector<int> predictedValue = {0, 0, 2, 2, 1};
//     ClassificationReport Class(trueValue, predictedValue);
//     Class.confusionMatrix(trueValue, predictedValue);
//     std::map<int, double> Precision = Class.precision();
//     std::cout << "Class No.  Precision\n";
//     for (auto it : Precision)
//     {
//         std::cout << it.first << " " << (double)it.second << std::endl;
//     }
//     std::map<int, double> Accuracy = Class.accuracy();
//     std::cout << "Class No.  Accuracy\n";
//     for (auto it : Accuracy)
//     {
//         std::cout << it.first << " " << (double)it.second << std::endl;
//     }
//     std::map<int, double> Recall = Class.recall();
//     std::cout << "Class No.  Recall\n";
//     for (auto it : Recall)
//     {
//         std::cout << it.first << " " << (double)it.second << std::endl;
//     }
//     std::map<int, double> F1_score = Class.precision();
//     std::cout << "Class No.  F1_Score\n";
//     for (auto it : F1_score)
//     {
//         std::cout << it.first << " " << (double)it.second << std::endl;
//     }
// }
