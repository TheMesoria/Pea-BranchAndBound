#include "GreedyAlg.hpp"
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>

// HACK
CityMap::Path GreedyAlgorithm::getClosestCity(const CityMap& map,
	std::vector<size_t>& notVisited,
	const unsigned& start)
{
	if (notVisited.empty()) { return CityMap::Path(); }

	auto citiesAviable = map.getMap()[start];
	auto bestCityId = findMinElement(citiesAviable, notVisited);
	auto bestCity = citiesAviable[bestCityId];

	auto bestPath = getClosestCity(map, notVisited, bestCityId);
	bestPath.paths.push_back(bestCity);
	bestPath.length += bestCity;

	return bestPath;
}

unsigned GreedyAlgorithm::findMinElement(
	const std::vector<unsigned>& val, 
	std::vector<unsigned>& notVisited)
{
	auto best= val[notVisited[0]];
	auto knownBest = 0u;
	auto knownBestInNotVisited = 0u;
	auto it = 0u;

	for (auto var : notVisited)
	{
		if (val[var] <= best || best == 0)
		{
			best = val[var];
			knownBest = var;
			knownBestInNotVisited = it;
		}
		it++;
	}
	path_.push_back(notVisited[knownBestInNotVisited]);
	notVisited.erase(notVisited.begin()+knownBestInNotVisited);
	return knownBest;
}

CityMap::Path GreedyAlgorithm::operator()(const CityMap &cities, const unsigned &startPoint)
{
	auto map = cities.getMap();
	std::vector<unsigned> notVisited;
	for (auto i = 0u; i < map.size(); i++)
	{
		if (startPoint != i)
			notVisited.push_back(i);
	}
	
	path_.push_back(startPoint);

	auto path = getClosestCity(cities, notVisited, startPoint);
	path.paths.push_back(cities.getMap()[startPoint][path_.back()]);
	path.cities = path_;
	path.length += cities.getMap()[startPoint][path_.back()];
	
	path_ = std::list<unsigned>();
	return path;
}
