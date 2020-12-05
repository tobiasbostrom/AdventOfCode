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

    std::pair<int, int> currentPos = { 3, 1 };
    int xMax = treeMap[0].length();
    int yMax = treeMap.size();
    int result = 0;

    while (currentPos.second < yMax)
    {
        if (treeMap[currentPos.second][currentPos.first % xMax] == '#')
        {
            result++;
        }

        currentPos.first = currentPos.first + 3;
        currentPos.second = currentPos.second + 1;
    }

    std::cout << result;

    return 0;
}
