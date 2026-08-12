#pragma once

#include <vector>

void findOptimalRoute(int startCity, int endCity, const std::vector<std::vector<int>>& roads);
void findDijkstraOptimalRoute(int startCity, int endCity, const std::vector<std::vector<int>>& roads);
void printVector(std::vector<int> vec);
void updateCityVectors(std::vector<int>* visited, std::vector<int>* unvisited, int city_index);