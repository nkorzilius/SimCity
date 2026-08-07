#include <vector>

class MapGenerator {
    public:
        MapGenerator(int max_amount_cities);
        
        std::vector<std::vector<int>> getRoads() const;
    private:
        std::vector<std::vector<int>> roads;
        int max_amount_cities;
        void generateMap();
        void printRoads();
        void addRoadToCities(int city1, int city2);
};