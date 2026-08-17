#pragma once
#include <cstdlib>
#include <ctime>
#include <vector>

class MapGenerator {
    public:
        MapGenerator(int max_amount_cities);
        
        std::vector<std::vector<int>> getRoads() const;
    private:
        std::vector<std::vector<int>> m_roads;
        int m_max_amount_cities;

        void generateMap();
        void addRoadToCities(int city1, int city2);
};