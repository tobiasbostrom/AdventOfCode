#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <utility>
#include <vector>

struct Bag
{
    Bag(std::string type) : type(std::move(type)), content() {}

    std::string type;
    std::vector<std::pair<std::shared_ptr<Bag>, int> >  content;
};

int getContainedBags(std::shared_ptr<Bag> bag)
{
    int ret = 1;

    if (!bag->content.empty())
    {
        for (auto& containedBag : bag->content)
        {
            ret = ret + getContainedBags(containedBag.first) * containedBag.second;
        }
    }

    return ret;
}

int main() {

    std::ifstream input1;
    input1.open("day7/input1.txt");

    std::string line;
    std::map<std::string, std::shared_ptr<Bag> > bags;
    int result = 0;

    while (getline(input1, line))
    {
        std::vector<std::pair<std::shared_ptr<Bag>, int> > containedBags;
        size_t pos = 0;
        std::string del1 = " bags contain ";
        pos = line.find(del1);

        std::shared_ptr<Bag> bag;
        std::string bagType = line.substr(0, pos);
        if (bags.contains(bagType))
        {
            bag = bags[bagType];
        } else
        {
            bag = std::make_shared<Bag>(bagType);
            bags[bagType] = bag;
        }

        if (line.find("contain no other") == std::string::npos)
        {
            line.erase(0, pos + del1.length());
            std::string del2 = ", ";

            while ((pos = line.find(del2)) != std::string::npos) {
                int numberOfBags = std::stoi(line.substr(0, 1));
                size_t endPos = line.find(" bag");

                std::shared_ptr<Bag> containedBag;
                std::string containedBagType = line.substr(2, endPos - 2);

                if (bags.contains(containedBagType)) {
                    containedBag = bags[containedBagType];
                } else {
                    containedBag = std::make_shared<Bag>(containedBagType);
                    bags[containedBagType] = containedBag;
                }

                containedBags.push_back(std::make_pair(containedBag, numberOfBags));
                line.erase(0, pos + del2.length());
            }

            int numberOfBags = std::stoi(line.substr(0, 1));
            size_t endPos = line.find(" bag");

            std::shared_ptr<Bag> containedBag;
            std::string containedBagType = line.substr(2, endPos - 2);

            if (bags.contains(containedBagType)) {
                containedBag = bags[containedBagType];
            } else {
                containedBag = std::make_shared<Bag>(containedBagType);
                bags[containedBagType] = containedBag;
            }

            containedBags.push_back(std::make_pair(containedBag, numberOfBags));
        }

        bags[bagType]->content = std::move(containedBags);
    }

    result = getContainedBags(bags["shiny gold"]) - 1;

    std::cout << result;

    return 0;
}