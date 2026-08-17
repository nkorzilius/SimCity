#include "DisplayPrint.hpp"

void printRoads(std::vector<std::vector<int>> roads)
{
    for (int i = 0; i < (int)roads.size(); i++) {
        std::cout << "City " << i << " Connections: [";
        for (int j = 0; j < (int)roads[i].size(); j++) {
            if (j !=0)
            {
                std::cout << ", ";
            }
            std::cout << roads[i][j];
        }
        std::cout << "]" <<std::endl;
    }
}

void printVector(std::vector<int> vec)
{
    std::cout << "[";
    for (int i=0; i<(int)vec.size(); i++)
    {
        std::cout<< vec[i] << " ";
    }
    std::cout << "]" << std::endl;
    std::cout << "------------------ " << std::endl;
}