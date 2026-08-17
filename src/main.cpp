#include "MapGenerator.hpp"
#include "OptimalRouteFinder.hpp"
#include "DisplayInteraction.hpp"
const int MAX_AMOUNT_CITIES = 20;

int main() {
    std::pair<int, int> cities = askUserInputCities(MAX_AMOUNT_CITIES);
    MapGenerator map_generator(MAX_AMOUNT_CITIES);
    OptimalRouteFinder route_finder(MAX_AMOUNT_CITIES);
    route_finder.findOptimalRoute(map_generator.getRoads(), cities.first, cities.second);
    return 0;
}
