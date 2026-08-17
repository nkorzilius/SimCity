#include <gtest/gtest.h>
#include "MapGenerator.hpp"
#include <algorithm>

TEST(MapGeneratorTest, mapCeneratedWithMaxAmountCities)
{
    // Given:
    int max_amount_cities = 10;
    // When:
    MapGenerator generator(max_amount_cities);
    std::vector<std::vector<int>> roads = generator.getRoads();
    // Then
    EXPECT_EQ(roads.size(), max_amount_cities);
}

TEST(MapGeneratorTest, allCitiesHaveAtLeastTwoRoads)
{
    // Given:
    int max_amount_cities = 10;
    // When:
    MapGenerator generator(max_amount_cities);
    std::vector<std::vector<int>> roads = generator.getRoads();
    // Then
    for (const auto& city_roads : roads) {
        EXPECT_GE(city_roads.size(), 2);
    }
}

TEST(MapGeneratorTest, allCitiesHaveMaxCitiesMinusOneRoads)
{
    // Given:
    int max_amount_cities = 5;
    // When:
    MapGenerator generator(max_amount_cities);
    std::vector<std::vector<int>> roads = generator.getRoads();
    // Then
    for (const auto& city_roads : roads) {
        EXPECT_LE(city_roads.size(), max_amount_cities-1);
    }
}

TEST(MapGeneratorTest, allCitiesHaveUniqueRoads)
{
    // Given:
    int max_amount_cities = 8;
    // When:
    MapGenerator generator(max_amount_cities);
    std::vector<std::vector<int>> roads = generator.getRoads();
    // Then
    for (const auto& city_roads : roads) {
        std::vector<int> unique_roads = city_roads;
        std::sort(unique_roads.begin(), unique_roads.end());
        unique_roads.erase(std::unique(unique_roads.begin(), unique_roads.end()), unique_roads.end());
        EXPECT_EQ(unique_roads.size(), city_roads.size());
    }
}

TEST(MapGeneratorTest, eachCityIsConnectedToPreviousCity)
{
    // Given:
    int max_amount_cities = 5;
    // When:
    MapGenerator generator(max_amount_cities);
    std::vector<std::vector<int>> roads = generator.getRoads();
    // Then
    for (int i = 1; i < max_amount_cities; ++i) 
    {
        std::vector<int> city_roads = roads[i];
        EXPECT_NE(std::find(city_roads.begin(), city_roads.end(), i - 1), city_roads.end());
    }
}
