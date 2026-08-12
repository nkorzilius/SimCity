#include "MapGenerator.hpp"
#include "OptimalRouteFinder.hpp"

const int MAX_AMOUNT_CITIES = 20;
const int START_CITY = 0;
const int END_CITY = 5;

int main() {
    MapGenerator map_generator(MAX_AMOUNT_CITIES);
    findDijkstraOptimalRoute(START_CITY, END_CITY, map_generator.getRoads());
    return 0;
}

