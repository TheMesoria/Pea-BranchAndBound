#include <iostream>
#include "../City/Map.hpp"

#include "BranchBoundAlghorithm.hpp"

BranchBoundAlghorithm::BranchBoundAlghorithm(const CityMap & map, const CityMap::Path & bestPath)
{
	map_ = &map;
	bestPath_ = bestPath;
}

std::optional<bool> BranchBoundAlghorithm::start()
{
	std::cout << "\nLaunching...\n";
	std::cout << "Data: \n" << bestPath_.toString() << "\n\n\n\t\t\t START:\n\n";

	std::list<unsigned> cities;
	for (auto i = 0u; i < map_->getMap().size(); i++) { cities.push_back(i); }

	auto result = handle(CityMap::Path(), cities);
	if (result == std::nullopt) { std::cout << "There have been problems found while running...\n"; }

	return result;
}

const unsigned & BranchBoundAlghorithm::getDistance(CityMap::Path& path)
{
	unsigned cityA = path.cities[path.cities.size()-1], cityB = path.cities[path.cities.size() - 2];

	return map_->getMap()[cityA][cityB];
}

std::optional<bool> BranchBoundAlghorithm::execute(CityMap::Path current, std::list<unsigned>& citiesLeft)
{
	if (citiesLeft.empty())
	{
		current.cities.push_back(current.cities.front());
		current.paths.push_back(getDistance(current));
		current.length += current.paths.back();
		if (bestPath_.length > current.length)
		{
			bestPath_ = current;
		}
		current.cities.pop_back();
		current.length -= current.paths.back();
		current.paths.pop_back();
		return false;
	}

	unsigned size = citiesLeft.size();
	for (auto i = 0u; i < size; i++)
	{
		//Add Element to front
		current.cities.push_back(citiesLeft.front());
		//Remove Element from list of not visited
		citiesLeft.pop_front();
		/// Situation :
		/// Current have all cities which he will visit in iteration

		current.paths.push_back(getDistance(current));
		current.length += current.paths.back();

		if (current.length < bestPath_.length)
		{
			execute(current, citiesLeft);
		}


		citiesLeft.push_back(current.cities.back());
		current.cities.pop_back();
		current.length -= current.paths.back();
		current.paths.pop_back();
	}	
	return true;
}



std::optional<bool> BranchBoundAlghorithm::handle(CityMap::Path current, std::list<unsigned>& citiesLeft)
{
	for (auto i=0u; i<citiesLeft.size();i++)
	{
		current.cities.push_back(citiesLeft.front());
		citiesLeft.pop_front();

		auto result = execute(current,citiesLeft);
		if (result == std::nullopt) { return std::nullopt; }


		citiesLeft.push_back(current.cities.back());
		current.cities.pop_back();
	}
}
