#include "GreedyAlg.hpp"
#include <stdio.h>

// HACK
CityMap::Path GreedyAlgorithm::getClosestCity(const CityMap& cities, std::vector<unsigned>& unselectedCities, CityMap::Path& selectedCities, const unsigned& start) const
{
	auto argVec = cities.getMap().at(start);

	if (unselectedCities.empty())
	{ 
		selectedCities.length += argVec[selectedCities.cities[0]];
		selectedCities.cities.push_back(selectedCities.cities[0]);
		return selectedCities;
	}
	if (selectedCities.cities.empty()) 
	{
		selectedCities.cities.push_back(unselectedCities.at(start));
		unselectedCities.erase(unselectedCities.begin() + start);
	}
	else
	{
		argVec[start] = INF;
	}
	
	auto minIterator = std::min_element(argVec.begin(),argVec.end());
	auto minElement = findMinElement(argVec,unselectedCities);
	
	selectedCities.length += argVec[minElement];
	printf("Length: %d\n", selectedCities.length);
	selectedCities.cities.push_back(unselectedCities.at(minElement));
	unselectedCities.erase(unselectedCities.begin() + minElement);

	return getClosestCity(cities, unselectedCities, selectedCities, selectedCities.cities.back());
}

size_t GreedyAlgorithm::findMinElement(const std::vector<unsigned>& val, const std::vector<unsigned> &cities) const
{
	CityMap::Path path;
	path.cities = val;
	CityMap::Path path2;
	path2.cities = cities;
	
	printf("\nOptions aviable: %s\nPaths: %s\n\n", path.toString().c_str(), path2.toString().c_str());

	size_t minEl; unsigned minVal=INF;
	for (auto i=0; i<cities.size();i++)
	{
		if (val[cities[i]] < minVal)
		{
			minEl = i;
			minVal = val[cities[i]];
			printf("\tVal INSIDE: %d\n", minVal);
		}
	}
	printf("Choosen val: %d, choosen id: %d\n", val[cities[minEl]], minEl);
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
