/**
 * @file ducks/io/io.hpp
 *
 * Header file including the io module of ducks.
 */

#ifndef SLOWMOKIT_IO_HPP
#define SLOWMOKIT_IO_HPP

#include "../../core.hpp"

class IO
{
public:
    /**
     * @brief Function to read a csv file
     * @param path: the path of the csv file to be read
     * @returns A 2D vector, carrying the data of the csv file
     */
    static std::vector<std::vector<int>> readCsv(std::string path);
};


#endif //SLOWMOKIT_IO_HPP
