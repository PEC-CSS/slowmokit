
#include "../slowmokit/ducks/ducks.hpp"

int main()
{
    std::vector<std::vector<int>> a = IO::readCsv("lol.csv");
    for(const auto& v: a)
    {
        for(auto d: v)
        {
            std::cout << d << " ";
        }
        std::cout << "\n";
    }
    return 0;
}
