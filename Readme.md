# Sim City

## Assignment
### Context
Imagine that you have a city of people in a remote land. Being that there's a lot of space lying around, they are constantly expanding. \
They do so in the following fashion: 
- First, a group of people break away from the main city ("city 0") and build a new city. 
- After doing so they build two roads, one to the most recently constructed city and one back to one other randomly chosen city that has already been built. 

This process continues for an indefinite number of cities. The first city to be built only builds a road back to city 0. You don't care about the 'real life' physical location of the cities, just assume that they exist and that the roads between them are all of equal length.

### Part 1
Write a program to simulate this expansion. Your code should work for up to 20 cities. You should have a variable somewhere in your code that controls how many cities to simulate. After you're done simulating the expansion you should print some output showing each city and which other cities it is connected to. For example:

City 0    Connections: [1, 2, 3]\
City 1    Connections: [0, 2]\
City 2    Connections: [1, 0, 3]\
City 3    Connections: [2, 0]

### Part 2
Now, imagine that you've been asked by this nation's postal service to write a program to determine the quickest path from one city to another. Assuming that all roads between cities are of equal length, write some code to find the shortest path between any two given cities. Your code should work for any two input cities, and print out the path as a list of cities.

For the example above, this might look like: Shortest Path from City 3 to City 1: [3, 2, 1]

## Solution 

### Part 1
Generating the cities and roads is implemented in `MapGenerator`. \
Based on the `max_amount_of_cities`, generates a matrix `roads` (`vector<vector<int>>`).\
The random number generator uses a seed based on time so that it generates a different set of connections each time.

### Part 2
Finding the optimal route based on the generated cities and connections is implemented in `OptimalRouteFinder`.

Using the Dijkstra Algorithm for finding the optimal route between 2 cities given vertex length (here every vertex length = 1)

Dijkstra algorithm:
1. Create a set of unvisited nodes (cities) and a set of visited nodes (cities).
2. Assign a tentative distance value to every node: set it to zero for our initial node and to inifite for all others
3. Calculate the tentative distance of each unvisited neighbor of the current node. Compare the newly calculated tentative distance to the current assigned value and assign the smaller one.

## Run Program

Clone the repository:
```sh
git clone https://github.com/nkorzilius/SimCity.git SimCity
```

Navigate to the directory containing the code
```sh
cd SimCity
```

Configure:
```sh
cmake -S . -B build
```

Build:
```sh
cmake --build build
```

Run:
```sh
./build/SimCity
```