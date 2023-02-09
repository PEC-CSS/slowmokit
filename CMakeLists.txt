cmake_minimum_required(VERSION 3.24)
project(slowmokit C CXX)

set(CMAKE_CXX_STANDARD 20)

include_directories(src/slowmokit)

add_library(slowmokit
        # the master file
        src/slowmokit.hpp

        # base files
        src/slowmokit/base.hpp
        src/slowmokit/core.hpp
        src/slowmokit/prereqs.hpp

        # ducks
        src/slowmokit/ducks/ducks.hpp
        src/slowmokit/ducks/io/io.hpp
        src/slowmokit/ducks/io/io.cpp
        src/slowmokit/ducks/matrix/matrix.hpp
        src/slowmokit/ducks/matrix/matrix.cpp

        # methods
        src/slowmokit/models/model.hpp
        src/slowmokit/methods/neighbors/knn/knn.cpp
        src/slowmokit/methods/neighbors/knn/knn.hpp
        src/slowmokit/methods/linear_model/linear_regression.hpp
        src/slowmokit/methods/linear_model/linear_regression/linear_regression.hpp
        src/slowmokit/methods/linear_model/linear_regression/linear_regression.cpp
        src/slowmokit/methods/cluster/kMeans/kMeans.cpp
        src/slowmokit/methods/cluster/kMeans/kMeans.hpp
        src/slowmokit/methods/cluster/kMeans.hpp
        src/slowmokit/methods/metrics/accuracy.hpp
        src/slowmokit/methods/metrics/accuracy.cpp
        src/slowmokit/methods/preprocessing/normalization.hpp
        src/slowmokit/methods/preprocessing/normalization.cpp
        src/slowmokit/methods/preprocessing/standardization.hpp
        src/slowmokit/methods/preprocessing/standardization.cpp
        src/slowmokit/methods/neighbors/bernoulli_nb.hpp
        src/slowmokit/methods/neighbors/bernoulli_nb/bernoulli_nb.hpp
        src/slowmokit/methods/neighbors/bernoulli_nb/bernoulli_nb.cpp
        src/slowmokit/methods/linear_model/logistic_regression.hpp
        src/slowmokit/methods/linear_model/logistic_regression/logistic_regression.hpp
        src/slowmokit/methods/linear_model/logistic_regression/logistic_regression.cpp
        src/slowmokit/methods/preprocessing/label_encoder.cpp
        src/slowmokit/methods/preprocessing/label_encoder.hpp
        src/slowmokit/methods/metrics/classification_report.hpp
        src/slowmokit/methods/metrics/classification_report.cpp
        src/slowmokit/methods/neighbors/gaussian_nb.hpp
        src/slowmokit/methods/neighbors/gaussian_nb/gaussian_nb.cpp
        src/slowmokit/methods/neighbors/gaussian_nb/gaussian_nb.hpp
        src/slowmokit/methods/neighbors/knn.hpp
        src/slowmokit/methods/neighbors/knn/knn.hpp
        src/slowmokit/methods/neighbors/knn/knn.cpp
        src/slowmokit/methods/preprocessing/one_hot_encoder.hpp
        src/slowmokit/methods/preprocessing/one_hot_encoder.cpp
        src/slowmokit/methods/metrics/precision.hpp
        src/slowmokit/methods/metrics/precision.cpp
        src/slowmokit/methods/metrics/recall.hpp
        src/slowmokit/methods/metrics/recall.cpp
        src/slowmokit/methods/metrics/mean_squared_error.hpp
        src/slowmokit/methods/metrics/mean_squared_error.cpp)
