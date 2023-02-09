/**
 * @file methods/cluster/DBSCAN/DBSCAN.hpp
 *
 * The header file for DBSCAN
 */
#ifndef SLOWMOKIT_DBSCAN_HPP
#define SLOWMOKIT_DBSCAN_HPP

#include "core.hpp"
/**
 * Class carrying implementation of the DBSCAN clustering algorithm
 * @tparam T type of the data to be clustered
 */
template<class T>
class DBSCAN
{
private:

    /**
     * Measure of how close a point should be to be considered in the vicinity of another point, default value is 0.5
     */
    long double eps;

    /**
     * Minimum number of points that should lie in the vicinity of a point for it to be considered a core point, default value is 5
     */
    int minSamples;

    /**
     * Labels assigned to each data point after fitting, the values range from 0 to clusters - 1, outliers are assigned -1
     */
    std::vector<int> labels;

    /**
     * Evaluates the euclidean distance between two feature vectors
     * @param p1 the first feature vector
     * @param p2 the second feature vector
     * @return the euclidean distance between the two vectors
     * @throws invalid_argument exception when the feature vectors are unequal in size
     */
    long double euclideanDistance(std::vector<T> p1, std::vector<T> p2);

    /**
     * Helper function for recursively clustering the points using DBSCAN
     * @param i index of the the point that is to be assigned a cluster
     * @param core boolean vector indicating whether a point is a core point or not
     * @param neighbours 2D vector carrying neighbours of each of the core points
     * @param label label of the cluster to be assigned to this point
     */
    void cluster(int i, std::vector<int> &core, std::vector<std::vector<int>> &neighbours, int &label);

public:

    /**
     * Constructor for creating an instance of the DBSCAN class
     * @param eps measure of how close a point should be to be considered in the vicinity of another point, default is 0.5
     * @param minSamples minimum number of points that should lie in the vicinity of a point for it to be considered a core point, default is 5
     * @throws invalid_argument exception when eps or minSamples is less than 0
     */
    DBSCAN(long double eps = 0.5, int minSamples = 5);

    /**
     * Fits and clusters the given training set
     * @param x list of feature vectors to be clustered
     */
    void fit(std::vector<std::vector<T>> x);

    /**
     * Fits and clusters the given training set and returns the labels assigned to each data point
     * @param x list of feature vectors
     * @return vector of labels assigned to each data point
     */
    std::vector<int> fitPredict(std::vector<std::vector<T>> x);

    /**
     * Returns the labels assigned to each data point of the training set fitted into the model
     * @return vector of labels assigned to each data point
     */
    std::vector<int> getLabels();
};

#endif //SLOWMOKIT_DBSCAN_HPP
