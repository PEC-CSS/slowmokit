/**
 * @file methods/neighbors/DBSCAN/DBSCAN.cpp
 *
 * Implementation of the DBSCAN class
 */

#include "DBSCAN.hpp"

template<class T>
DBSCAN<T>::DBSCAN(long double eps, int minSamples) {
    if(eps < 0 || minSamples < 0) {
        throw std::invalid_argument("Values can't be negative");
    }
    this->eps = eps;
    this->minSamples = minSamples;
}

template<class T>
long double DBSCAN<T>::euclideanDistance(std::vector<T> p1, std::vector<T> p2) {
    long double distance = 0.0;
    if(p1.size() != p2.size()) {
        throw std::invalid_argument("Feature vectors are unequal in size");
    }
    int n = p1.size();
    for(int i = 0; i < n; i++) {
        distance += (long double) (p1[i] - p2[i]) * (p1[i] - p2[i]);
    }
    return sqrtl(distance);
}

template<class T>
void DBSCAN<T>::cluster(int i, std::vector<int> &core, std::vector<std::vector<int>> &neighbours, int &label) {
    if(labels[i] != -1) {
        return;
    }
    labels[i] = label;
    if(core[i] != 0) {
        for(int j : neighbours[i]) {
            cluster(j, core, neighbours, label);
        }
    }
}

template<class T>
void DBSCAN<T>::fit(std::vector<std::vector<T>> x) {
    int n = x.size();

    std::vector<int> core(n);
    std::vector<std::vector<int>> neighbours(n, std::vector<int>());

    labels = std::vector<int>(n, -1);

    for(int i = 0; i < n; i++) {
        std::vector<int> neighbourIndices;
        for(int j = 0; j < n; j++) {
            if(i == j) {
                continue;
            }
            if(euclideanDistance(x[i], x[j]) <= eps) {
                neighbourIndices.push_back(j);
            }
        }
        int const samples = neighbourIndices.size();
        if(samples >= minSamples) {
            core[i]++;
            neighbours[i] = neighbourIndices;
        }
    }
    int clusters = 0;
    for(int i = 0; i < n; i++) {
        if(core[i] == 0 || labels[i] != -1) {
            continue;
        }
        cluster(i, core, neighbours, clusters);
        clusters++;
    }
}

template<class T>
std::vector<int> DBSCAN<T>::fitPredict(std::vector<std::vector<T>> x) {
    fit(x);
    return labels;
}

template<class T>
std::vector<int> DBSCAN<T>::getLabels() {
    return labels;
}