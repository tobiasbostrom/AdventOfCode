#include <iostream>
#include <fstream>
#include <string>
#include <set>

int main() {

    std::ifstream input1;
    input1.open("day6/input1.txt");

    std::string line;
    std::set<char> questions;
    int result = 0;

    while (getline(input1, line))
    {
        if (line.empty())
        {
            result += questions.size();
            questions.clear();
        }
        else
        {
            for (const auto& answer : line)
            {
                questions.insert(answer);
            }
        }
    }
    result += questions.size();
    questions.clear();

    std::cout << result;

    return 0;
}
