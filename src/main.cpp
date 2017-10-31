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

int main(int argc, char *args[])
{
	CityMap map(args[1]);
	auto path = GreedyAlgorithm();
	CityMap::Path shortestPath(9999'9999);
	for (auto i = 0; i < 5; i++) 
	{ 
		auto tmp = path(map, i);
		if (tmp.length <= shortestPath.length)
		{
			shortestPath = tmp;
		}
	}
	

	BranchBoundAlghorithm BB(map, CityMap::Path(9999'9999));
	auto x = BB.start();

	std::cout << "\n\n" << BB.getResult().toString() << std::endl;

	system("pause");
	return EXIT_SUCCESS;
}