#pragma once
#include "../City/Map.hpp"
#include <memory>
#include <algorithm>

class GreedyAlgorithm 
{
	CityMap::Path getClosestCity(const CityMap& cities, 
		std::vector<unsigned>& unselectedCities, 
		CityMap::Path& selectedCities=CityMap::Path(), 
		const unsigned& start=0) const;

	size_t findMinElement(const std::vector<unsigned> &val, const std::vector<unsigned> &cities) const;
	
	std::vector<unsigned> prepareCities(const size_t& count) const;
public:
	static const unsigned INF = 9999;

	CityMap::Path operator()(const CityMap& cities, 
		const unsigned& startPoint) const;
};
