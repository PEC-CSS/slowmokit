/**
 * @file ducks/io/io.cpp
 *
 * Implementation of the io main program
 */

#include "io.hpp"

std::vector<std::vector<int>> IO::readCsv(std::string path)
{
    std::ifstream file(path);
    std::string columns;
    std::getline(file, columns);
    std::string row;

    std::vector<std::vector<int>> df;

    while (std::getline(file, row))
    {
        size_t pos = 0;
        std::vector<int> temp;
        while ((pos = row.find(',')) != std::string::npos)
        {
            std::string token = row.substr(0, pos);
            temp.push_back(std::stoi(token));
            row.erase(0, pos + 1);
        }
        temp.push_back(stoi(row));
        df.push_back(temp);
    }
    
    file.close();
    return df;
}