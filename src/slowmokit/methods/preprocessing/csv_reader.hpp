/**
 * @file methods/preprocessing/csv_reader.hpp
 *
 * Easy include To Return the csv read data
 */

#ifndef SLOWMOKIT_CSV_READER_HPP
#define SLOWMOKIT_CSV_READER_HPP

#include "../../core.hpp"

template <class T>
std::vector<std::vector<std::string>> readCsv(std::string name, bool index);

#endif // SLOWMOKIT_CSV_READER_HPP