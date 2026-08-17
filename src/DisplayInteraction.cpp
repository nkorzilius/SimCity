#include "DisplayInteraction.hpp"

void printRoads(std::vector<std::vector<int>> roads)
{
    for (int i = 0; i < (int)roads.size(); i++) {
        std::cout << "City " << i << " Connections: ";
        printVector(roads[i]);
    }
}

void printVector(std::vector<int> vec)
{
    std::cout << "[";
    for (int i = 0; i < (int)vec.size(); i++) 
    {
        if (i !=0)
        {
            std::cout << ", ";
        }
        std::cout << vec[i];
    }
    std::cout << "]" <<std::endl;

}

std::pair<int, int> askUserInputCities(const int MAX_AMOUNT_CITIES)
{
    std::cout << "Entering Starting City" << std::endl;
    int start_city = askUserInputCity(MAX_AMOUNT_CITIES);
    int end_city;

    std::cout << "Entering Ending City" << std::endl;
    while (true)
    {
        end_city = askUserInputCity(MAX_AMOUNT_CITIES);
        if (end_city != start_city)
            break;

        std::cout << "Start and End City are the same, enter different number than " << start_city << std::endl;
    }
    return {start_city, end_city};
}

int askUserInputCity(const int MAX_AMOUNT_CITIES)
{
    std::cout << "Enter number in range [0-" << MAX_AMOUNT_CITIES-1 << "]"<< std::endl;
    int city_index;
    int userInput;
    bool input_valid = false;
    while (!input_valid)
    {
        std::cin >> userInput;
        if (userInput >= 0 && userInput <= MAX_AMOUNT_CITIES)
        {
            city_index = userInput;
            input_valid = true;
        }
        else
        {
            std::cout << "Invalid input, enter number in range [0-"<< MAX_AMOUNT_CITIES << "]"<< std::endl;
        }
    }
    return city_index;
}
