#include "MapGenerator.hpp"
#include <iostream>

MapGenerator::MapGenerator(int max_amount_cities) {
    std::cout << "MapGenerator constructor reached! " << std::endl;
    this->max_amount_cities = max_amount_cities;
    generateMap();
}

std::vector<std::vector<int>> MapGenerator::getRoads() const
{
    return roads;
}

void MapGenerator::generateMap()
{
    roads = {{}};
    srand(time(0)); // Setting random number seed so that it generates different random numbers each time the program is run

    for (int i = 1; i < max_amount_cities; i++) {
        roads.push_back({});
        // Road to most recent city:
        addRoadToCities(i, i - 1);
        // Road to other random city already build:
        if (i != 1)
        {
            int random_city = rand() % (i - 1); // Range [0-(i-2)]
            addRoadToCities(i, random_city);
        }
    }

    printRoads();
}

void MapGenerator::addRoadToCities(int city1, int city2)
{
    roads[city1].push_back(city2);
    roads[city2].push_back(city1);
}


void MapGenerator::printRoads()
{
    for (int i = 0; i < roads.size(); i++) {
        std::cout << "City " << i << " Connections: [";
        for (int j = 0; j < roads[i].size(); j++) {
            if (j !=0)
            {
                std::cout << ", ";
            }
            std::cout <<roads[i][j];
        }
        std::cout << "]" <<std::endl;
    }
}