#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

struct Entry
{
    int min, max;
    char character;
    std::string password;
};

int main() {

    std::ifstream input1;
    input1.open("day2/input1.txt");

    std::string line;
    std::vector<Entry> entries;
    while (getline(input1, line))
    {
        std::string delimiter("-");
        size_t pos = line.find(delimiter);
        std::string min = line.substr(0, pos);
        line.erase(0, pos + delimiter.length());

        delimiter = " ";
        pos = line.find(delimiter);
        std::string max = line.substr(0, pos);
        line.erase(0, pos + delimiter.length());

        delimiter = ": ";
        pos = line.find(delimiter);
        char character = line[0];
        line.erase(0, pos + delimiter.length());

        Entry entry = { std::stoi(min), std::stoi(max), character, line };
        entries.push_back(entry);
    }

    int result = 0;

    for (const auto& entry : entries)
    {
        if (entry.min <= entry.password.size() &&
            entry.max <= entry.password.size())
        {
            if ((entry.password[entry.min - 1] == entry.character) !=
                (entry.password[entry.max - 1] == entry.character))
            {
                result++;
            }
        }
    }

    std::cout << result;

    return 0;
}