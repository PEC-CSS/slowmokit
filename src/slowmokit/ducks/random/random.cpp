/**
 * @file ducks/matrix/matrix.cpp
 *
 * Implementation of the matrix main program
 */

#include "random.hpp"

template <class RealType>
RealType random(RealType L, RealType R)
{
	std::mt19937 rng(seed);
	if (! std::is_floating_point<RealType>())
		throw std::domain_error("Both parameter must be floating point only.");

	if (L > R)
		throw std::range_error(
		    "Start element of range must be less than equal to "
		    "End element of range.");

	return std::uniform_real_distribution<RealType>(L, R)(rng);
}

template <class IntType>
IntType randint(IntType L, IntType R)
{
	std::mt19937 rng(seed);
	if (! std::is_integral<IntType>() and ! std::is_unsigned<IntType>())
		throw std::domain_error(
		    "Both parameter must be signed or unsigned integer type only.");

	if (L > R)
		throw std::range_error(
		    "Start element of range must be less than equal to "
		    "End element of range.");

	return std::uniform_int_distribution<IntType>(L, R)(rng);
}