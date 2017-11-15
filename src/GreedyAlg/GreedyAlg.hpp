#pragma once
#include "../City/Map.hpp"
#include <memory>
#include <algorithm>

class GreedyAlgorithm 
{
	std::list<unsigned> path_;

private:
	CityMap::Path getClosestCity(
		const CityMap& map, 
		std::vector<size_t>& notVisited,
		const unsigned& start = 0 );

	unsigned findMinElement(
		const std::vector<unsigned> &val,
		std::vector<unsigned> &notVisited);

public:
	static const unsigned INF = 9999;

	CityMap::Path operator()(
		const CityMap& cities, 
		const unsigned& startPoint) ;
};
