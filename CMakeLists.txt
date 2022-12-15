cmake_minimum_required(VERSION 3.24)
project(slowmokit C CXX)

set(CMAKE_CXX_STANDARD 17)

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

        # methods
        src/slowmokit/models/model.hpp
        src/slowmokit/methods/neighbors/knn/knn.cpp
        src/slowmokit/methods/neighbors/knn/knn.hpp
        )