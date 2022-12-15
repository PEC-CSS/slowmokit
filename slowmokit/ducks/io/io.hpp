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
