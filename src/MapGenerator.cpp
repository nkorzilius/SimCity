#include "MapGenerator.hpp"
#include "DisplayInteraction.hpp"

MapGenerator::MapGenerator(int max_amount_cities) {
    this->m_max_amount_cities = max_amount_cities;
    generateMap();
}

std::vector<std::vector<int>> MapGenerator::getRoads() const
{
    return m_roads;
}

void MapGenerator::generateMap()
{
    m_roads = {{}};
    srand(time(0));

    for (int i = 1; i < m_max_amount_cities; i++) {
        m_roads.push_back({});
        // Road to most recent city:
        addRoadToCities(i, i - 1);
        // Road to other random city already build:
        if (i != 1)
        {
            int random_city = rand() % (i - 1); // Range [0-(i-2)]
            addRoadToCities(i, random_city);
        }
    }

    printRoads(m_roads);
}

void MapGenerator::addRoadToCities(int city1, int city2)
{
    m_roads[city1].push_back(city2);
    m_roads[city2].push_back(city1);
}
