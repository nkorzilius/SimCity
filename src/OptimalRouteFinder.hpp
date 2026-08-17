#pragma once

#include <vector>
#include <algorithm>
#include <limits>
#include <iostream>

class OptimalRouteFinder{
    public:
        OptimalRouteFinder(int max_cities);

        void findOptimalRoute(const std::vector<std::vector<int>>& roads, int start_city, int end_city);
        std::vector<int> getDistances();
        std::vector<std::vector<int>> getOptimalRoutes();
    private:
        void findDijkstraOptimalRoute(const std::vector<std::vector<int>>& roads);
        void updateCityVectors(int city_index);
        int getNextCityIndex(int current_index, const std::vector<std::vector<int>>& roads);
        bool cityAlreadyVisited(int city);
        bool cityUnvisited(int city);

        int m_start_city;
        int m_end_city;
        int m_max_cities;
        std::vector<int> m_visited_cities;
        std::vector<int> m_unvisited_cities;
        std::vector<int> m_distances;
        std::vector<std::vector<int>> m_optimal_routes;
};
