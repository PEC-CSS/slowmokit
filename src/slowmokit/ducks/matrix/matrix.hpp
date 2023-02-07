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
private:
    /**
     * n: Row Dimension
     * m: Column Dimension
     */
    int n, m;
    std::vector<std::vector<T>> mat;

    /**
     * @brief function to updating shape to current matrix shape
     * @throws AssertionError incase any dimension is zero
     */
    void updateShape()
    {
        assert(std::size(mat) > 0 and std::size(mat[0]) > 0 and "Cannot have empty dimension");
        n = std::size(mat);
        m = std::size(mat[0]);
    }
    
public:
    /**
     * @constructor to initialise Matrix object with all zero and given dimension
     * @param n: row dimension
     * @param m: column dimension
     * @throws std::out_of_range exception if any dimension is non-positive
     */
    Matrix(int, int);


    /**
     * @constructor to initialise Matrix Object
     * @param in: 2D vector used to initialise matrix
     * @throws std::out_of_range exception if any dimension is non-positive
     * @throws std::invalid_argument exception if row dimension is not consistent
     */
    Matrix(const std::vector<std::vector<T>>);


    /**
     * @brief Overloading *= to multiply a matrix with a scalar
     * @param scalar: Number with which you want to multiply matrix with
     * @returns: Matrix after multiplying current matrix with scalar
     */
    template<class G>
    Matrix &operator *=(const G &);


    /**
     * @brief Overloading *= operator to multiply matrix with another Matrix
     * @param rhs: Multiply this->mat with another Matrix: rhs
     * @returns: A New Matrix after multiplying with matrix `rhs`
     * @throws: std::out_of_range exception if any dimension is non-positive
     * @throws: std::invalid_argument exception if dimensions of two matrices are not compatible for multiplication
     */
    Matrix &operator *=(const Matrix &);


    /**
     * @brief Overloading += to add a matrix with a scalar
     * @param scalar: Number with which you want to add matrix with
     * @returns: Matrix after adding current matrix with scalar
     */
    template<class G>
    Matrix &operator +=(const G &);


    /**
     * @brief Overloading -= to subtract a matrix with a scalar
     * @param scalar: Number with which you want to subtract matrix with
     * @returns: Matrix after subtracting scalar from current matrix 
     */
    template<class G>
    Matrix &operator -=(const G &);


    /**
     * @brief function to get dimension of the matrix
     */
    std::array<int, 2> getShape() const;


    /**
     * @brief Function for taking dot product of current matrix with another matrix
     * @param rhs: Take dot product of current Matrix with `rhs`
     * @returns: A New Matrix after taking dot product with matrix `rhs`
     * @throws: std::invalid_argument incase of incompatible dimensions
     */
    Matrix &dot(const Matrix &);


    /**
     * @brief overloading += operator for adding another matrix to existing matrix
     * @param1: Matrix `rhs` which is to be added
     * @throws: std::invalid_argument incase of incompatible dimensions
     */
    Matrix &operator += (const Matrix &rhs);


    /**
     * @brief overloading -= operator for subtracting another matrix from existing matrix
     * @param rhs: Matrix `rhs` which is to be added
     * @throws: std::invalid_argument incase of incompatible dimensions
     */
    Matrix &operator -= (const Matrix &rhs);


    /**
     * @brief overloading () operator to easily access element
     * @param i: which row to access
     * @param j: which column to access
     * @throw: std::out_of_range if i and j go out of bound
     */
    T &operator() (int, int);


    /**
     * @brief overloading [] operator to easily access element
     * @param i: which row to access
     * @throw: std::out_of_range if i and j go out of bound
     */
    const std::vector<T> &operator[] (int) const;


     /**
     * @brief This function will multiply two matrix
     * @param rhs: This is the matrix which will be multiplied with the main matrix
     * @throw: whatever operator *= throws
     */
    Matrix matmul(const Matrix);


    /**
     * @brief This function will add 2 matrix
     * @param rhs: This is the matrix which will be added with the main matrix
     * @throw: whatever operator *= throws
     */
    Matrix add(const Matrix);


    /**
     * @brief This function will subtract 2 matrix
     * @param rhs: This is the matrix which will be subtracted from the main matrix
     * @throw: whatever operator *= throws
     */
    Matrix subtract(const Matrix); 
};


/**
 * @brief overloading << for easy printing of Matrix
 */
template<class T>
std::ostream& operator<<(std::ostream &, const Matrix<T> &);

/**
 * @brief Free Function to multiply a matrix to a number or another matrix
 * @param lhs: A number or a Matrix
 * @param rhs: A number (only if lhs is not a number) or a Matrix
 * @returns Matrix Object
 */
template <class T, class G> Matrix<T> operator*(G, const Matrix<T> &);
template <class T, class G> Matrix<T> operator*(Matrix<T>, const G &);
template <class T> Matrix<T> operator*(Matrix<T>, const Matrix<T> &);

/**
 * @brief Free Function to add a matrix to a number or another matrix
 * @param lhs: A number or a Matrix
 * @param rhs: A number (only if lhs is not a number) or a Matrix
 * @returns Matrix Object
 */
template <class T, class G> Matrix<T> operator+(G, const Matrix<T> &);
template <class T, class G> Matrix<T> operator+(Matrix<T>, const G &);
template <class T> Matrix<T> operator+(Matrix<T>, const Matrix<T> &);

/**
 * @brief Free Function to subtract a matrix to a number or another matrix
 * @param lhs: A number or a Matrix
 * @param rhs: A number (only if lhs is not a number) or a Matrix
 * @returns Matrix Object
 */
template <class T, class G> Matrix<T> operator-(G, const Matrix<T> &);
template <class T, class G > Matrix<T> operator-(Matrix<T>, const G &);
template <class T> Matrix<T> operator-(Matrix<T>, const Matrix<T> &);


#endif //SLOWMOKIT_IO_HPP
