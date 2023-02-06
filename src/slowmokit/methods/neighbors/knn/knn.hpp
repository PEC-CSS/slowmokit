/**
 * @file methods/neighbors/knn/knn.hpp
 *
 * The header file including the knn
 */
#ifndef SLOWMOKIT_KNN_HPP
#define SLOWMOKIT_KNN_HPP

#include "../../../models/model.hpp"

template <class T>
class KNN{
private:
    std::vector<std::vector<T>> xTrain;
    std::vector<int> yTrain;
    double distance(std::vector<T> x1,std::vector<T> x2);
public:
    void fit(std::vector<std::vector<T>> x,std::vector<int> y,int k,int classNums);
    int predict(std::vector<T> test);
};

#endif // SLOWMOKIT_KNN_HPP
