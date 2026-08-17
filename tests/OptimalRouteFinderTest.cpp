#include <gtest/gtest.h>
#include "OptimalRouteFinder.hpp"

TEST(OptimalRouteFinderTest, optimalRouteFromStartCityToStartCityIsZero)
{
    // Given
    OptimalRouteFinder routeFinder(5);
    std::vector<std::vector<int>> roads = {
        {1, 2},
        {0, 3},
        {0, 4, 3},
        {1, 2, 4},
        {2, 3}
    };
    int startCity = 0;
    int endCity = 2;
    // When
    routeFinder.findOptimalRoute(roads, startCity, endCity);
    // Then
    std::vector<int> distances = routeFinder.getDistances();
    EXPECT_EQ(distances[startCity], 0);
}

TEST(OptimalRouteFinderTest, optimalRouteFromStartCityToEndCityIsGreaterThanZero)
{
    // Given
    OptimalRouteFinder routeFinder(5);
    std::vector<std::vector<int>> roads = {
        {1, 2},
        {0, 3},
        {0, 4, 3},
        {1, 2, 4},
        {2, 3}
    };
    int startCity = 0;
    int endCity = 2;
    // When
    routeFinder.findOptimalRoute(roads, startCity, endCity);
    // Then
    std::vector<int> distances = routeFinder.getDistances();
    EXPECT_GT(distances[endCity], 0);
}

TEST(OptimalRouteFinderTest, optimalRouteFromStartCityToEndCityContainsUniqueCities)
{
    // Given
    OptimalRouteFinder routeFinder(5);
    std::vector<std::vector<int>> roads = {
        {1, 2},
        {0, 3},
        {0, 4, 3},
        {1, 2, 4},
        {2, 3}
    };
    int startCity = 0;
    int endCity = 4;    
    // When
    routeFinder.findOptimalRoute(roads, startCity, endCity);
    // Then
    std::vector<std::vector<int>> optimalRoutes = routeFinder.getOptimalRoutes();
    std::vector<int> uniqueCities = optimalRoutes[endCity];
    std::sort(uniqueCities.begin(), uniqueCities.end());
    uniqueCities.erase(std::unique(uniqueCities.begin(), uniqueCities.end()), uniqueCities.end());
    EXPECT_EQ(uniqueCities.size(), optimalRoutes[endCity].size());
}

TEST(OptimalRouteFinderTest, optimalRouteFromStartCityToEndCityIsValid)
{
    // Given
    OptimalRouteFinder routeFinder(5);
    std::vector<std::vector<int>> roads = {
        {1, 2},
        {0, 3},
        {0, 4, 3},
        {1, 2, 4},
        {2, 3}
    };
    int startCity = 0;
    int endCity = 4;    
    // When
    routeFinder.findOptimalRoute(roads, startCity, endCity);
    // Then
    std::vector<std::vector<int>> optimalRoutes = routeFinder.getOptimalRoutes();
    std::vector<int> route = optimalRoutes[endCity];
    bool isValidRoute = true;
    for (size_t i = 0; i < route.size() - 1; ++i) {
        int currentCity = route[i];
        int nextCity = route[i + 1];
        if (std::find(roads[currentCity].begin(), roads[currentCity].end(), nextCity) == roads[currentCity].end()) {
            isValidRoute = false;
            break;
        }
    }
    EXPECT_TRUE(isValidRoute);
}

TEST(OptimalRouteFinderTest, allCitiesAreVisitedAtLeastOnce)
{
    // Given
    OptimalRouteFinder routeFinder(5);
    std::vector<std::vector<int>> roads = {
        {1, 2},
        {0, 3},
        {0, 4, 3},
        {1, 2, 4},
        {2, 3}
    };
    int startCity = 0;
    int endCity = 4;    
    // When
    routeFinder.findOptimalRoute(roads, startCity, endCity);
    // Then
    std::vector<int> distances = routeFinder.getDistances();
    for (int distance : distances) {
        EXPECT_NE(distance, std::numeric_limits<int>::max());
    }
}
