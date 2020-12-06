#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <iterator>

int main() {

    std::ifstream input1;
    input1.open("day6/input1.txt");

    std::string line;
    std::vector<std::set<char> > group;
    int result = 0;

    while (getline(input1, line))
    {
        if (line.empty())
        {
            std::set<char> lastPerson = group.back();
            group.pop_back();

            for (const auto& person : group)
            {
                std::set<char> intersection;
                std::set_intersection(lastPerson.begin(), lastPerson.end(),
                                      person.begin(), person.end(),
                                      std::inserter(intersection, intersection.begin()));
                lastPerson = intersection;
            }

            result += lastPerson.size();
            group.clear();
        }
        else
        {
            std::set<char> answers(line.begin(), line.end());
            group.push_back(answers);
        }
    }

    std::set<char> lastPerson = group.back();
    group.pop_back();

    for (const auto& person : group)
    {
        std::set<char> intersection;
        std::set_intersection(lastPerson.begin(), lastPerson.end(),
                              person.begin(), person.end(),
                              std::inserter(intersection, intersection.begin()));
        lastPerson = intersection;
    }

    result += lastPerson.size();
    group.clear();

    std::cout << result;

    return 0;
}