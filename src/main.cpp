//	PEA-Ormaniec-Branch&Bound
//	Created by Ormaniec
//	At 10/7/2017
//	All rights reserved
//

#include <string>
#include <iostream>
#include "City\Map.hpp"
#include "GreedyAlg\GreedyAlg.hpp"

int main(int argc, char *args[])
{
	CityMap map(args[1]);
	auto path = GreedyAlgorithm();
	CityMap::Path shortestPath();
	for (auto i = 0; i < 5; i++) { std::cout << path(map, i).toString() << "\n\n"; }
	system("pause");
	return EXIT_SUCCESS;
}