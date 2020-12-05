#include <iostream>
#include <fstream>
#include <vector>

int main() {

    std::ifstream input1;
    input1.open("day1/input1.txt");

    int value;
    std::vector<int> values;
    while (input1 >> value)
    {
        values.push_back(value);
    }

    for (auto& number1 : values)
    {
        for (auto& number2 : values)
        {
            if (number1 != number2)
            {
                if ((number1 + number2) == 2020)
                {
                    int result = number1 * number2;
                    std::cout << result << std::endl;
                    return 0;
                }
            }
        }

    }
    return 0;
}
