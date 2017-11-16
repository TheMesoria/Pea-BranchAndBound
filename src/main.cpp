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
#include <chrono>

void calculatePath(const CityMap &map, const bool &faster);

int main(int argc, char *args[])
{
	std::fstream file("results.res");
	std::vector<unsigned> resultsEmpty;
	std::vector<unsigned> resultsBoosted;
	for (auto i = 1u; i < 12; i++)
	{
		using namespace std;
		string name = to_string(i)+".tsp";

		auto xREAD = FileConverter::parsePoints(name);
		CityMap map(xREAD);

		std::cout << "\n\nELEMENT: " << i;

		auto start = chrono::steady_clock::now();
		calculatePath(map, false);
		auto end = chrono::steady_clock::now();
		auto result = end - start;

		resultsEmpty.push_back(chrono::duration_cast<chrono::milliseconds>(result).count());
	}


	system("pause");
	return EXIT_SUCCESS;
}

void calculatePath(const CityMap & map, const bool & faster)
{
	CityMap::Path shortestPath(9999'9999'9999);
	if (faster)
	{
		GreedyAlgorithm inst;
		for (auto i = 0u; i < map.getMap().size(); i++)
		{
			auto res = inst(map, i);
			if (res.length < shortestPath.length)
			{
				shortestPath = res;
			}
		}
	}

	BranchBoundAlghorithm BB(map, shortestPath);
	auto fin = BB.start();
	if (fin != std::nullopt) { std::cout << BB.getResult().toString() << std::endl; }
}
