#include "MapGenerator.hpp"
#include "OptimalRouteFinder.hpp"

const int MAX_AMOUNT_CITIES = 20;

int main() {
    MapGenerator map_generator(MAX_AMOUNT_CITIES);
    findOptimalRoute(0, 5, map_generator.getRoads());
    return 0;
}

