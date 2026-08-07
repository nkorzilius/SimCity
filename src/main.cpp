#include <iostream>
#include <vector>
using namespace std;

const int MAX_AMOUNT_CITIES = 20;

void printRoads(std::vector<std::vector<int>> roads)
{
    for (int i = 0; i < roads.size(); i++) {
        cout << "City " << i << " Connections: [";
        for (int j = 0; j < roads[i].size(); j++) {
            if (j !=0)
            {
                cout << ", ";
            }
            cout <<roads[i][j];
        }
        cout << "]" <<endl;
    }
}

void addRoadToCities(int city1, int city2, std::vector<std::vector<int>>& roads)
{
    roads[city1].push_back(city2);
    roads[city2].push_back(city1);
}

int main() {
    std::vector<std::vector<int>> roads = {{}};
    srand(time(0)); // Setting random number seed so that it generates different random numbers each time the program is run

    for (int i = 1; i < MAX_AMOUNT_CITIES; i++) {
        roads.push_back({});
        // Road to most recent city:
        addRoadToCities(i, i - 1, roads);
        // Road to other random city already build:
        if (i != 1)
        {
            int random_city = rand() % (i - 1); // Range [0-(i-2)]
            addRoadToCities(i, random_city, roads);
        }
    }

    printRoads(roads);
    return 0;
}

