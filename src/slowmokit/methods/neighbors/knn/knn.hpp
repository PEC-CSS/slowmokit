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
    int k=1;
    int classNums=1;
    /**
     * @brief Calculates distance euclidean/else
     * 
     * @param x1 first point
     * @param x2 second point
     * @return double value of distance
     */
    double distance(std::vector<T> x1,std::vector<T> x2);
public:
    /**
     * @brief store values of training data
     * 
     * @param x all x training values
     * @param y all y training values
     * @param k minimum number of nearest neighbors
     * @param classNums number of classes
     */
    void fit(std::vector<std::vector<T>> x,std::vector<int> y,int k,int classNums);
    /**
     * @brief predict to which cluster it belongs
     * 
     * @param test testing value
     * @return int cluster number to which it belongs
     */
    int predict(std::vector<T> test);
};

#endif // SLOWMOKIT_KNN_HPP
