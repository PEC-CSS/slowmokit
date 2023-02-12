/**
 * @file ducks/random/random.hpp
 *
 * Header file including the random  of ducks.
 */

#ifndef SLOWMOKIT_RANDOM_HPP
#define SLOWMOKIT_RANDOM_HPP

#include "../../core.hpp"

/**
 * @brief Function to get a real random number between two numbers L and R
 * inclusive
 * @param L: Starting element of the range
 * @param R: Ending element of the range
 * @returns a random number between L and R inclusive
 * @throws std::domain_error if L or R are not floating point type
 * @throws std::length_error exception if R > L
 */
template<class RealType>
RealType random(RealType, RealType);

/**
 * @brief Function to get a real random number between two numbers L and R
 * inclusive
 * @param L: Starting element of the range
 * @param R: Ending element of the range
 * @returns a random number between L and R inclusive
 * @throws std::domain_error if L or R is not signed/unsigned int or char
 * @throws std::length_error exception if R > L
 */
template<class IntType>
IntType randint(IntType, IntType);

/**
 * @brief seed for generating
 */
std::seed_seq seed {
    (uint32_t) std::chrono::duration_cast<std::chrono::nanoseconds>(
        std::chrono::high_resolution_clock::now().time_since_epoch())
        .count(),
    (uint32_t) std::random_device()(),
    (uint32_t) (uintptr_t) std::make_unique<char>().get(),
    (uint32_t) __builtin_ia32_rdtsc()};


#endif // SLOWMOKIT_RANDOM_HPP