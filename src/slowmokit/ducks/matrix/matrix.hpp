/**
 * @file ducks/matrix/matrix.hpp
 *
 * Header file including the matrix class of ducks.
 */

#ifndef SLOWMOKIT_IO_HPP
#define SLOWMOKIT_IO_HPP

#include "../../core.hpp"

template <class T = int>
class Matrix
{
    /**
     * n: Row Dimension
     * m: Column Dimension
     */
    int n, m;
    std::vector<std::vector<T>> mat;
public:
    /**
     * @constructor to initialise Matrix object with all zero and given dimension
     * @param n: row dimension
     * @param m: column dimension
     * @throws assertionError if any dimension is zero
     */
    Matrix(int, int);


    /**
     * @constructor to initialise Matrix project
     * @param in: 2D vector used to initialise matrix
     * @throws assertionError if any dimension is zero or column dimensions are not consistent with each other
     */
    Matrix(const std::vector<std::vector<T>>);


    /**
     * @brief Overloading *= to multiply a matrix with a scalar
     * @param scalar: Number with which you want to multiply matrix with
     * @returns: Matrix after multiplying current matrix with scalar
     */
    Matrix &operator *=(const T &);


    /**
     * @brief Overloading *= operator to multiply matrix with another Matrix
     * @param rhs: Multiply this->mat with another Matrix: rhs
     * @returns: A New Matrix after multiplying with matrix `rhs`
     * @throws: assertionError if rhs has any zero dimension
     * @throws: assertionError if dimensions of two matrices are not compatible for multiplication
     */
    Matrix &operator *=(const Matrix<T> &);

    /**
     * @bried function to get dimension of the matrix
     */
    std::array<int, 2> getShape();

    /**
     * TODO: Overload << instead of using this print method
     */
    void print();
};

#endif //SLOWMOKIT_IO_HPP
