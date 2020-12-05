#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <regex>

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
        std::smatch match;
        if (passport.contains("byr") &&
            passport.contains("iyr") &&
            passport.contains("eyr") &&
            passport.contains("hgt") &&
            passport.contains("hcl") &&
            passport.contains("ecl") &&
            passport.contains("pid"))
        {
            if (std::regex_match(passport.at("byr"), match, std::regex("([0-9]{4})")) &&
                stoi(match.str(1)) >= 1920 &&
                stoi(match.str(1)) <= 2002 &&
                std::regex_match(passport.at("iyr"), match, std::regex("([0-9]{4})")) &&
                stoi(match.str(1)) >= 2010 &&
                stoi(match.str(1)) <= 2020 &&
                std::regex_match(passport.at("eyr"), match, std::regex("([0-9]{4})")) &&
                stoi(match.str(1)) >= 2020 &&
                stoi(match.str(1)) <= 2030 &&
                std::regex_match(passport.at("hgt"), match, std::regex("([0-9]{2,3})(cm|in)")) &&
                (match.str(2) == "cm" && stoi(match.str(1)) >= 150 && stoi(match.str(1)) <= 193 ||
                 match.str(2) == "in" && stoi(match.str(1)) >= 59 && stoi(match.str(1)) <= 76) &&
                std::regex_match(passport.at("hcl"), std::regex("#[0-9,a-f]{6}")) &&
                std::regex_match(passport.at("ecl"), std::regex("(amb|blu|brn|gry|grn|hzl|oth)")) &&
                std::regex_match(passport.at("pid"), std::regex("[0-9]{9}")))
            {
                result++;
            }
        }
    }

    std::cout << result;

    return 0;
}