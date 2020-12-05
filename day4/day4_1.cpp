#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

typedef std::map<std::string, std::string> Passport;

int main() {

    std::ifstream input1;
    input1.open("day4/input1.txt");

    std::string line;
    Passport tempPassport;
    std::vector<Passport> passports;

    while (getline(input1, line))
    {
        if (line.empty())
        {
            passports.push_back(tempPassport);
            tempPassport.clear();
        }
        else
        {
            std::string entryDel = " ";
            std::string keyValueDel = ":";
            size_t pos = 0;
            std::string entry;
            while ((pos = line.find(entryDel)) != std::string::npos) {
                entry = line.substr(0, pos);
                line.erase(0, pos + entryDel.length());

                pos = entry.find(keyValueDel);
                tempPassport[entry.substr(0, pos)] = entry.substr(pos + keyValueDel.size());
            }
            pos = line.find(keyValueDel);
            tempPassport[line.substr(0, pos)] = line.substr(pos + keyValueDel.size());
        }
    }
    passports.push_back(tempPassport);

    int result = 0;

    for (const auto& passport : passports)
    {
        if (passport.contains("byr") &&
            passport.contains("iyr") &&
            passport.contains("eyr") &&
            passport.contains("hgt") &&
            passport.contains("hcl") &&
            passport.contains("ecl") &&
            passport.contains("pid"))
        {
            result++;
        }
    }

    std::cout << result;

    return 0;
}
