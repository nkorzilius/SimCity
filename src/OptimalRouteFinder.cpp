#include "OptimalRouteFinder.hpp"
#include "DisplayPrint.hpp"

OptimalRouteFinder::OptimalRouteFinder(int max_cities){
    this->m_max_cities = max_cities;
    for (int i = 0; i < max_cities; ++i)
        m_unvisited_cities.push_back(i);
}

void OptimalRouteFinder::findOptimalRoute(const std::vector<std::vector<int>>& roads) 
{
    askUserInputCities();
    findDijkstraOptimalRoute(roads);
}

void OptimalRouteFinder::findDijkstraOptimalRoute(const std::vector<std::vector<int>>& roads) 
{
    // Initialization: 
    std::vector<int> distances(roads.size(), std::numeric_limits<int>::max());
    distances[m_start_city] = 0;
    
    std::vector<std::string> optimal_route(roads.size(), "");
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
            if (distances[neighbor] > distances[city_index]+1)
            {
                distances[neighbor] = distances[city_index]+1;
                optimal_route[neighbor] = optimal_route[city_index]+ "->" + std::to_string(city_index);
            }
        }

        updateCityVectors(city_index);
    }

    std::cout << "Distances: " << std::endl;
    printVector(distances);
    std::cout << "Optimal Route from: " << m_start_city << " to " << m_end_city << std::endl;
    std::cout << optimal_route[m_end_city] << std::endl;
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

void OptimalRouteFinder::askUserInputCities()
{
    std::cout << "Entering Starting City" << std::endl;
    m_start_city = askUserInputCity();

    std::cout << "Entering Ending City" << std::endl;
    while (true)
    {
        m_end_city = askUserInputCity();
        if (m_end_city != m_start_city)
            break;

        std::cout << "Start and End City are the same, enter different number than " << m_start_city << std::endl;
    }
}

int OptimalRouteFinder::askUserInputCity()
{
    std::cout << "Enter number in range [0-" << m_max_cities-1 << "]"<< std::endl;
    int city_index;
    int userInput;
    bool input_valid = false;
    while (!input_valid)
    {
        std::cin >> userInput;
        if (userInput >= 0 && userInput <= m_max_cities)
        {
            city_index = userInput;
            input_valid = true;
        }
        else
        {
            std::cout << "Invalid input, enter number in range [0-"<< m_max_cities << "]"<< std::endl;
        }
    }
    return city_index;
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
