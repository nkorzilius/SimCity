#pragma once

#include <vector>

class OptimalRouteFinder{
    public:
        OptimalRouteFinder(int max_cities);

        void findOptimalRoute(const std::vector<std::vector<int>>& roads);
    private:
        void findDijkstraOptimalRoute(const std::vector<std::vector<int>>& roads);
        void printVector(std::vector<int> vec);
        void updateCityVectors(std::vector<int>* visited, std::vector<int>* unvisited, int city_index);
        void askUserInputCities();
        int askUserInputCity();

        int m_start_city;
        int m_end_city;
        int m_max_cities;
};
