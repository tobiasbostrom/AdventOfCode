#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main() {

    std::ifstream input1;
    input1.open("day3/input1.txt");

    std::string line;
    std::vector<std::string> treeMap;

    while (getline(input1, line))
    {
        treeMap.push_back(line);
    }

    std::vector<std::pair<int, int> > slopes = { {1, 1},
                                                 {3, 1},
                                                 {5, 1},
                                                 {7, 1},
                                                 {1, 2}};

    int xMax = treeMap[0].length();
    int yMax = treeMap.size();
    uint64_t result = 1;

    for (const auto& slope: slopes)
    {
        int subResult = 0;

        std::pair<int, int> currentPos = slope;

        while (currentPos.second < yMax)
        {
            if (treeMap[currentPos.second][currentPos.first % xMax] == '#')
            {
                subResult++;
            }

            currentPos.first = currentPos.first + slope.first;
            currentPos.second = currentPos.second + slope.second;
        }

        result *= subResult;
    }

    std::cout << result;

    return 0;
}