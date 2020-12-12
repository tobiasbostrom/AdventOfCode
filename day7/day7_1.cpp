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
    std::vector<std::shared_ptr<Bag>> content;


};

bool containsBagType(std::string bagType,
                     std::shared_ptr<Bag> bag)
{
    int ret = false;

    if (!bag->content.empty())
    {
        for (auto& containedBag : bag->content)
        {
            if (containedBag->type == bagType ||
                containsBagType(bagType, containedBag))
            {
                ret = true;
                break;
            }
        }
    }

    return ret;
}

int main()
{

    std::ifstream input1;
    input1.open("day7/input1.txt");

    std::string line;
    std::map<std::string, std::shared_ptr<Bag> > bags;
    int result = 0;

    while (getline(input1, line))
    {
        std::vector<std::shared_ptr<Bag>> containedBags;
        size_t pos = 0;
        std::string del1 = " bags contain ";
        pos = line.find(del1);

        std::shared_ptr<Bag> bag;
        std::string bagType = line.substr(0, pos);
        if (bags.contains(bagType))
        {
            bag = bags[bagType];
        }
        else
        {
            bag = std::make_shared<Bag>(bagType);
            bags[bagType] = bag;
        }

        if (line.find("contain no other") == std::string::npos)
        {
            line.erase(0, pos + del1.length());
            std::string del2 = ", ";

            while ((pos = line.find(del2)) != std::string::npos)
            {
                size_t endPos = line.find(" bag");

                std::shared_ptr<Bag> containedBag;
                std::string containedBagType = line.substr(2, endPos - 2);

                if (bags.contains(containedBagType))
                {
                    containedBag = bags[containedBagType];
                }
                else
                {
                    containedBag = std::make_shared<Bag>(containedBagType);
                    bags[containedBagType] = containedBag;
                }

                containedBags.push_back(containedBag);
                line.erase(0, pos + del2.length());
            }

            size_t endPos = line.find(" bag");

            std::shared_ptr<Bag> containedBag;
            std::string containedBagType = line.substr(2, endPos - 2);

            if (bags.contains(containedBagType))
            {
                containedBag = bags[containedBagType];
            }
            else
            {
                containedBag = std::make_shared<Bag>(containedBagType);
                bags[containedBagType] = containedBag;
            }

            containedBags.push_back(containedBag);
        }

        bags[bagType]->content = std::move(containedBags);
    }

    for (const auto& bag : bags)
    {
        if (containsBagType("shiny gold", bag.second))
        {
            result++;
        }
    }

    std::cout << result;

    return 0;
}
