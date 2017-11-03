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



std::optional<bool> BranchBoundAlghorithm::execute(CityMap::Path current, std::list<unsigned>& citiesLeft)
{
	if (citiesLeft.empty()) { return true; }

	auto currentCity = current.cities.back();

	try 
	{
		for (auto i=0u;i<citiesLeft.size();i++)
		{
			current.cities.push_back(citiesLeft.front());
			citiesLeft.pop_front();

			auto val = map_->getMap()[currentCity][current.cities.back()];
			auto over = val + current.length;


			// ============================
			// Check for length

			if (over < bestPath_.length) {

				current.length += val;
				current.paths.push_back(val);


				// ============================
				// Continue loop


				auto result = execute(current, citiesLeft);
				if (result == std::nullopt) { return std::nullopt; }
				if (result != false)
				{
					bestPath_ = current;
				}
			}

			/// ============================
			// Sum up

			current.length -= val;
			current.paths.pop_back();

			citiesLeft.push_back(current.cities.back());
			current.cities.pop_back();

			return false;
		}
	}
	catch(...)
	{
		std::cout << "\nWoah, it went aerial...\n" << current.toString();
		return std::nullopt;
	}
	return false;
}



std::optional<bool> BranchBoundAlghorithm::handle(CityMap::Path current, std::list<unsigned>& citiesLeft)
{
	for (auto i=0u; i<citiesLeft.size();i++)
	{
		current.cities.push_back(citiesLeft.front());
		citiesLeft.pop_front();
		citiesLeft.push_back(current.cities.back());

		auto result = execute(current,citiesLeft);
		if (result == std::nullopt) { return std::nullopt; }

		current.cities.pop_back();
	}
}
