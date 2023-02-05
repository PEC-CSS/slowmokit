/**
 * @file slowmokit.hpp
 *
 * Include all of the slowmokit! When this file is included, all components of slowmokit
 * are included.
 *
 */
#ifndef SLOWMOKIT_HPP
#define SLOWMOKIT_HPP

// core libraries
#include "slowmokit/core.hpp"
#include "slowmokit/base.hpp"
#include "slowmokit/prereqs.hpp"

// Methods
#include "slowmokit/methods/neighbors/knn/knn.hpp"
#include "slowmokit/methods/cluster/kMeans.hpp"
#include "slowmokit/methods/linear_model/linear_regression.hpp"
#include "slowmokit/methods/neighbors/bernoulli_nb.hpp"
#include "slowmokit/methods/neighbors/multinomial_nb.hpp"

#endif // SLOWMOKIT_HPP
