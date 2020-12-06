#include <iostream>
#include <fstream>
#include <string>

int decodeNumber(std::string bspString, int min, int max)
{
    if (min == max && bspString.empty())
    {
        return min;
    }
    else if (bspString.empty())
    {
        return -1;
    }
    else
    {
        if (bspString[0] == 'F' || bspString[0] == 'L')
        {
            return decodeNumber(bspString.substr(1), min, max - ((max - min + 1) / 2));
        }
        else if (bspString[0] == 'B' || bspString[0] == 'R')
        {
            return decodeNumber(bspString.substr(1), min + ((max - min + 1) / 2), max);
        }
        else
        {
            return -2;
        }
    }
}

int main()
{

    std::ifstream input1;
    input1.open("day5/input1.txt");

    std::string line;
    int result = 0;

    while (getline(input1, line))
    {
        int row = decodeNumber(line.substr(0, 7), 0, 127);
        int column = decodeNumber(line.substr(7), 0, 7);
        int seatId = row * 8 + column;

        if (seatId > result)
        {
            result = seatId;
        }
    }

    std::cout << result;

    return 0;
}
