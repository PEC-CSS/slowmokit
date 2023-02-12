//#include "../../src/slowmokit/methods/neighbors/categorical_nb/categorical_nb.hpp"
//#include "../../src/slowmokit/core.hpp"
//
//signed main() {
//
//    std::vector <std::vector<std::string>> xTrain = {{"fifa", "yes", "no",  "no"},
//                                                     {"fifa", "no",  "yes", "no"},
//                                                     {"fifa", "no",  "no",  "yes"},
//                                                     {"cc",   "no",  "no",  "yes"},
//                                                     {"fifa", "yes", "yes", "yes"},
//                                                     {"cc",   "yes", "yes", "yes"},
//                                                     {"cc",   "no",  "no",  "yes"},
//                                                     {"cc",   "yes", "no",  "no"}};
//    std::vector <std::string> yTrain = {"m", "m", "m", "m", "f", "f", "f", "f"};
//    std::vector <std::string> xTest = {"fifa", "no", "yes", "yes"};
//    categoricalNB<std::string> classifier;
//    std::cout << classifier.fitPredict(xTrain, yTrain, xTest);
//
//}