# TestTask №4

This program calculates the maximum possible width for a tank named Armata to travel from the capital city to Zodanga in the road network of the planet Basrum. The road network is represented as an adjacency list with random road widths.

# Files

main.cpp: The main program with logic to generate or read test data, find the maximum possible width, and display the result.

graph.h and graph.cpp: These files contain the implementation of the graph-related functions, including generating or reading the road network, performing DFS, and finding the minimum road width.

random.h and random.cpp: Files contain the random generation of integer and real numbers.


# Input format

Firstly, user should choose format: R or I - in R format data will generate randomly, in I format data will be taken from file "input.txt"

If user chooses I format, data in input file should be as follows:

```php
<numCities> <numRoads>
<city1> <city2> <width>
<city1> <city2> <width>
...

```

# Output format

If there are no paths between Capital and Zodanga, program will show message: "No paths between Capital and Zodanga", otherwise, it will show the maximum possible value of Armata's width.
