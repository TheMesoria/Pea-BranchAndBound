//	PEA-Ormaniec-Branch&Bound
//	Created by Ormaniec
//	At 10/7/2017
//	All rights reserved
//

#include <string>
#include <iostream>
#include "City\Map.hpp"
#include "GreedyAlg\GreedyAlg.hpp"
#include "B&BAlg\BranchBoundAlghorithm.hpp"
#include "Converter\FileConverter.hpp"

int main(int argc, char *args[])
{
	auto xREAD = FileConverter::parsePoints("a280.tsp");
	CityMap map3(xREAD);

	for each (auto var in map3.getMap())
	{
		for each (auto var2 in var)
		{
			std::cout << var2 << " ";
		}
		std::cout << std::endl <<std::endl;
	}

	CityMap map("map.txt");
	auto path = GreedyAlgorithm();
	CityMap::Path shortestPath(9999'9999);
	for (auto i = 0; i < map.getMap().size(); i++) 
	{ 
		auto tmp = path(map, i);
		if (tmp.length <= shortestPath.length)
		{
			shortestPath = tmp;
		}
	}

	std::cout << shortestPath.toString() << "\n\n\n\n";

	BranchBoundAlghorithm BB(map, CityMap::Path(9999'9999));
	auto x = BB.start();

	std::cout << "\n\n" << BB.getResult().toString() << std::endl;

	system("pause");
	return EXIT_SUCCESS;
}