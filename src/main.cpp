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

int main() {
    std::vector<int> cities = {0};
    std::vector<std::vector<int>> roads = {{}};

    for (int i = 1; i < MAX_AMOUNT_CITIES; i++) {
        cities.push_back(i);
        std::vector<int> city_roads;
        // Road to most recent city:
        city_roads.push_back(i - 1);
        // Road to other random city already build:
        if (i != 1)
        {
            int random_city = rand() % (i - 1); // Range [0-(i-2)]
            city_roads.push_back(random_city);
        }
        roads.push_back(city_roads);
    }

    printRoads(roads);
    return 0;
}

