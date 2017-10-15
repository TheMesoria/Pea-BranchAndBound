#include "GreedyAlg.hpp"
#include <stdio.h>

CityMap::Path GreedyAlgorithm::getClosestCity(const CityMap& cities, std::vector<unsigned>& unselectedCities, CityMap::Path& selectedCities, const unsigned& start) const
{
	if (unselectedCities.empty()){ return selectedCities; }

	selectedCities.cities.push_back(unselectedCities.at(start));
	unselectedCities.erase(unselectedCities.begin() + start);

	auto argVec = cities.getMap().at(start);
	auto minIterator = std::min_element(argVec.begin(),argVec.end());
	auto minElement = findMinElement(argVec,unselectedCities);
	
	selectedCities.length += argVec[minElement];

	return getClosestCity(cities, unselectedCities, selectedCities, selectedCities.cities.back());
}

size_t GreedyAlgorithm::findMinElement(const std::vector<unsigned>& val, const std::vector<unsigned> &cities) const
{
	CityMap::Path path;
	path.cities = val;
	
	printf("Options aviable: %s\n", path.toString().c_str());

	size_t minEl; unsigned minVal=INF;
	for (auto i=0; i<cities.size();i++)
	{
		if (val[cities[i]] < minVal)
		{
			minEl = i;
			minVal = val[cities[i]];
		}
	}
	printf("Choosen val: %d, choosen id: %d\n", minVal, minEl);
	return minEl;
}

std::vector<unsigned> GreedyAlgorithm::prepareCities(const size_t & count) const
{
	std::vector<unsigned> temp;
	for (size_t i = 0; i < count; i++) { temp.push_back(i); }
	return temp;
}

CityMap::Path GreedyAlgorithm::operator()(const CityMap &cities, const unsigned &startPoint) const
{
	CityMap::Path shortestPath;

	return getClosestCity(cities, prepareCities(cities.getMap().size()), shortestPath, startPoint);
}
