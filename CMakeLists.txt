cmake_minimum_required(VERSION 3.24)
project(slowmokit)

set(CMAKE_CXX_STANDARD 14)

include_directories(slowmokit)
include_directories(slowmokit/cluster/agglomerative_clustering)
include_directories(slowmokit/cluster/dbscan)
include_directories(slowmokit/cluster/kmeans)
include_directories(slowmokit/linear_model/linear_regression)
include_directories(slowmokit/linear_model/logistic_regression)
include_directories(slowmokit/models)
include_directories(slowmokit/neighbors/knn)
include_directories(slowmokit/preprocessing/label_encoder)
include_directories(slowmokit/preprocessing/min_max_scale)
include_directories(slowmokit/preprocessing/one_hot_encoder)
include_directories(slowmokit/svm)

add_library(slowmokit
        slowmokit/cluster/agglomerative_clustering/agglomerative_clustering.cpp
        slowmokit/cluster/agglomerative_clustering/agglomerative_clustering.h
        slowmokit/cluster/dbscan/dbscan.cpp
        slowmokit/cluster/dbscan/dbscan.h
        slowmokit/cluster/kmeans/kmeans.cpp
        slowmokit/cluster/kmeans/kmeans.h
        slowmokit/linear_model/linear_regression/linear_regression.cpp
        slowmokit/linear_model/linear_regression/linear_regression.h
        slowmokit/linear_model/logistic_regression/logistic_regression.cpp
        slowmokit/linear_model/logistic_regression/logistic_regression.hpp
        slowmokit/models/model.hpp
        slowmokit/preprocessing/label_encoder/label_encoder.cpp
        slowmokit/preprocessing/label_encoder/label_encoder.h
        slowmokit/preprocessing/min_max_scale/min_max_scale.cpp
        slowmokit/preprocessing/min_max_scale/min_max_scale.h
        slowmokit/preprocessing/one_hot_encoder/one_hot_encoder.cpp
        slowmokit/preprocessing/one_hot_encoder/one_hot_encoder.h
        slowmokit/svm/svm.cpp
        slowmokit/svm/svm.h
        slowmokit/base.hpp
        slowmokit/core.hpp
        slowmokit/prereqs.hpp slowmokit/neighbors/knn/knn.cpp slowmokit/neighbors/knn/knn.hpp)
