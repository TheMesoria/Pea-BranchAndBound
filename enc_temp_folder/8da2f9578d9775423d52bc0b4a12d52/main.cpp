//	PEA-Ormaniec-Branch&Bound
//	Created by Ormaniec
//	At 10/7/2017
//	All rights reserved
//

#include <string>
#include <iostream>
#include <memory>
#include "City\Map.hpp"
#include "GreedyAlg\GreedyAlg.hpp"

int main(int argc, char *args[])
{
	CityMap map(args[1]);
	auto path = GreedyAlgorithm();
	std::shared_ptr<CityMap::Path> shortestPath=nullptr;
	for (auto i = 0; i < 5; i++) 
	{ 
		if (shortestPath)
		{
			auto p = path(map, i);
			if (shortestPath.get()->length < p.length)
			{
				shortestPath.reset(&p);
			}
		}
		else
		{
			shortestPath.reset(&path(map,i));
		}
	}
	std::cout << shortestPath->toString();
	system("pause");
	return EXIT_SUCCESS;
}