#include <iostream>
#include <fstream>
#include <vector>

int main() {

    std::ifstream input1;
    input1.open("day1/input1.txt");

    int64_t value;
    std::vector<int64_t> values;
    while (input1 >> value)
    {
        values.push_back(value);
    }

    for (auto& number1 : values)
    {
        for (auto& number2 : values)
        {
            for (auto& number3 : values)
            {
                if (number1 != number2 != number3) {
                    if ((number1 + number2 + number3) == 2020) {
                        int64_t result = number1 * number2 * number3;
                        std::cout << result << std::endl;
                        return 0;
                    }
                }
            }
        }

    }
    return 0;
}