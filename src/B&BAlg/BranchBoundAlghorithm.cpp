#include <iostream>
#include "../City/Map.hpp"
#include <chrono>

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

	unsigned cityB = path.cities.back();
	path.cities.pop_back();
	unsigned cityA = path.cities.back();
	path.cities.push_back(cityB);

	return map_->getMap()[cityA][cityB];
}

std::optional<bool> BranchBoundAlghorithm::execute(CityMap::Path current, std::list<unsigned>& citiesLeft)
{
	if (citiesLeft.empty())
	{
		current.cities.push_back(current.cities.front());
		auto dist = getDistance(current);

		if (dist + current.length < bestPath_.length)
		{
			current.length += dist;
			current.paths.push_back(dist);
			bestPath_ = current;
		}
		current.cities.pop_back();
		return false;;
	}

	auto size = citiesLeft.size();
	for (auto i = 0u; i < size; i++)
	{
		current.cities.push_back(citiesLeft.front());
		citiesLeft.pop_front();
		current.paths.push_back(getDistance(current));
		if (current.length + current.paths.back() < bestPath_.length)
		{
			current.length += current.paths.back();
			execute(current, citiesLeft);
			current.length -= current.paths.back();
		}
		citiesLeft.push_back(current.cities.back());
		current.paths.pop_back();
		current.cities.pop_back();
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
