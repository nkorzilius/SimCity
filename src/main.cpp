#include <iostream>
#include <vector>
using namespace std;

int main() {
    int max_amount_cities = 20;
    std::vector<int> cities = {0};

    for (int i = 1; i < max_amount_cities; i++) {
        cities.push_back(i);
    }

    return 0;
}