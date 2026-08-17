#include "OptimalRouteFinder.hpp"
#include "DisplayInteraction.hpp"

OptimalRouteFinder::OptimalRouteFinder(int max_cities)
{
    this->m_max_cities = max_cities;
    for (int i = 0; i < max_cities; ++i)
        m_unvisited_cities.push_back(i);
    m_distances.assign(max_cities, std::numeric_limits<int>::max());
    m_optimal_routes.assign(max_cities, std::vector<int>{});
}

std::vector<int> OptimalRouteFinder::getDistances() 
{
    return m_distances;
}

std::vector<std::vector<int>> OptimalRouteFinder::getOptimalRoutes() 
{
    return m_optimal_routes;
}

void OptimalRouteFinder::findOptimalRoute(const std::vector<std::vector<int>>& roads, int start_city, int end_city) 
{
    m_end_city = end_city;
    m_start_city = start_city;
    m_distances[m_start_city] = 0;
    findDijkstraOptimalRoute(roads);
}

void OptimalRouteFinder::findDijkstraOptimalRoute(const std::vector<std::vector<int>>& roads) 
{
    // Initialization:     
    int city_index = m_start_city;

    // Loop over all cities to calculate the distance to all other cities:
    while (!m_unvisited_cities.empty())
    {
        // Updating city Index:
        if (!m_visited_cities.empty())
        {
            city_index = getNextCityIndex(city_index, roads);
            // if new city_index already visited:
            if (cityAlreadyVisited(city_index))
            {
                std::cout << "Selected City already Visited, Unvisited cities: " << std::endl;
                printVector(m_unvisited_cities);
                break;
            }
        }
        // Updating Distances & optimal route: 
        for (auto neighbor: roads[city_index])
        {
            if (m_distances[neighbor] > m_distances[city_index]+1)
            {
                m_distances[neighbor] = m_distances[city_index]+1;
                m_optimal_routes[neighbor] = m_optimal_routes[city_index];
                m_optimal_routes[neighbor].push_back(city_index);
            }
        }

        updateCityVectors(city_index);
    }

    std::cout << "Distances: " << std::endl;
    printVector(m_distances);
    std::cout << "Optimal Route from: " << m_start_city << " to " << m_end_city << std::endl;
    printVector(m_optimal_routes[m_end_city]);
}

void OptimalRouteFinder::updateCityVectors(int city_index)
{
    m_visited_cities.push_back(city_index);

    auto it = std::find(m_unvisited_cities.begin(), m_unvisited_cities.end(), city_index);
    if (it != m_unvisited_cities.end())
    {
        m_unvisited_cities.erase(it);
    }
}

int OptimalRouteFinder::getNextCityIndex(int current_index, const std::vector<std::vector<int>>& roads)
{
    int next_index = current_index;
    std::vector<int> neighbours = roads[current_index];
    // Check if any of the currently selected neighbours has not been visited yet:
    for (int neighbour : neighbours)
    {
        // Select the first unvisited neighbour as the next city to visit:
        if (cityUnvisited(neighbour))
        {
            return neighbour;
        }
    }
    // If all neighbours have been visited, Check if any of the neighbours neighbours has not been visited yet!
    for (int neighbour : neighbours)
    {
        for (int subneighbour : roads[neighbour])
        {
            if (cityUnvisited(subneighbour))
            {
                return subneighbour;
            }
        }
    }
    return next_index;
}

bool OptimalRouteFinder::cityAlreadyVisited(int city)
{
    return std::find(m_visited_cities.begin(), m_visited_cities.end(), city) != m_visited_cities.end();
}

bool OptimalRouteFinder::cityUnvisited(int city)
{
    return std::find(m_unvisited_cities.begin(), m_unvisited_cities.end(), city) != m_unvisited_cities.end();
}
