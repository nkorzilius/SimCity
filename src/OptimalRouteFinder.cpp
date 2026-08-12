#include "OptimalRouteFinder.hpp"
#include <algorithm>
#include <limits>
#include <iostream>

void findOptimalRoute(const std::vector<std::vector<int>>& roads) 
{
    std::cout << roads.size() << std::endl;
    int startCity;
    int endCity;
    std::pair<int,int> city_indices;
    city_indices = askUserInputCities(roads.size());
    findDijkstraOptimalRoute(city_indices.first, city_indices.second, roads);
}

// Dijkstra algorithm:
// 1. Create a set of unvisited nodes (cities) and a set of visited nodes (cities).
// 2. Assign a tentative distance value to every node: set it to zero for our initial node and to inifite for all others
// 3. Calculate the tentative distance of each unvisited neighbor of the current node. Compare the newly calculated tentative distance to the current assigned value and assign the smaller one.

void findDijkstraOptimalRoute(int startCity, int endCity, const std::vector<std::vector<int>>& roads) 
{
    // Initialization: 
    std::vector<int> distances(roads.size(), std::numeric_limits<int>::max());
    distances[startCity] = 0;
    std::vector<int> visited_cities;
    std::vector<int> unvisited_cities;
    for (int i = 0; i < static_cast<int>(roads.size()); ++i)
        unvisited_cities.push_back(i);
    
    std::vector<std::string> optimal_route(roads.size(), "");
    int city_index = startCity;

    // Loop over all cities to calculate the distance to all other cities:
    while (!unvisited_cities.empty())
    {
        for (auto neighbor: roads[city_index])
        {
            if (distances[neighbor] > distances[city_index]+1)
            {
                distances[neighbor] = distances[city_index]+1;
                optimal_route[neighbor] = optimal_route[city_index]+ "->" + std::to_string(city_index);
            }
        }
        updateCityVectors(&visited_cities, &unvisited_cities, city_index);
        // Select the next city to visit from the unvisited cities:
        for (int neighbour : roads[city_index])
        {
            if (std::find(unvisited_cities.begin(), unvisited_cities.end(), neighbour) != unvisited_cities.end())
            {
                city_index = neighbour;
                break;
            }
        }
    }

    std::cout << "Distances: " << std::endl;
    printVector(distances);
    std::cout << "Optimal Route from: " << startCity << " to " << endCity << std::endl;
    std::cout << optimal_route[endCity] << std::endl;
}

void updateCityVectors(std::vector<int>* visited, std::vector<int>* unvisited, int city_index)
{
    visited->push_back(city_index);

    auto it = std::find(unvisited->begin(), unvisited->end(), city_index);
    if (it != unvisited->end())
    {
        unvisited->erase(it);
    }
}

void printVector(std::vector<int> vec)
{
    std::cout << "[";
    for (int i=0; i<vec.size(); i++)
    {
        std::cout<< vec[i] << " ";
    }
    std::cout << "]" << std::endl;
    std::cout << "------------------ " << std::endl;
}

std::pair<int, int> askUserInputCities(int max_cities)
{
    std::cout << "Entering Starting City" << std::endl;
    int startCity = askUserInputCity(max_cities);
    std::cout << "Entering Ending City" << std::endl;
    int endCity = askUserInputCity(max_cities);

    return {startCity, endCity};
}

int askUserInputCity(int max_cities)
{
    std::cout << "Enter number in range [0-" << max_cities-1 << "]"<< std::endl;
    int city_index;
    int userInput;
    bool input_valid = false;
    while (!input_valid)
    {
        std::cin >> userInput;
        if (userInput >= 0 && userInput <= max_cities)
        {
            city_index = userInput;
            input_valid = true;
        }
        else
        {
            std::cout << "Invalid input, enter number in range [0-"<< max_cities << "]"<< std::endl;
        }
    }
    return city_index;
}
