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
    int classNums;
    std::string distType;
    /**
     * @brief Calculates distance euclidean/manhattan
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
     * @param classNums number of classes
     */
    void fit(std::vector<std::vector<T>> x,std::vector<int> y,int classNums);
    /**
     * @brief predict to which class it belongs
     * 
     * @param test vector containing the test input
     * @param k minimum number of nearest neighbors
     * @param distType distance type euclidean/manhattan
     * @return int class number to which it belongs
     */
    int predict(std::vector<T> test,int k,std::string distType);
};

#endif // SLOWMOKIT_KNN_HPP
