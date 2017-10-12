#include "Map.hpp"
#include <iostream>

CityMap::CityMap(const std::string & fileName)
{
	LoadToMap(fileName);
}

CityMap::~CityMap()
{
}

void CityMap::PrintValueTriangle() const
{
	for (size_t i = 0; i < cities_.size(); i++)
	{
		for (size_t j = 0; j < cities_[i].size(); j++)
		{
			std::cout << cities_[i][j];
		}

		std::cout << std::endl;
	}
}

void CityMap::LoadToMap(const std::string & fileName)
{
	size_t					cityCount(0);
	size_t					actualCity(0);

	std::vector<unsigned>	tempReadVector;
	std::fstream			file(fileName, std::ios::in);

	if (!file)
	{
		std::cerr << "File read failed: " << fileName << std::endl;
		return;
	}

	// Read Header
	file >> cityCount;

	// Read Cities
	while (!file.eof())
	{
		unsigned value;
		file >> value;

		tempReadVector.push_back(value);
		if (file.peek() == '\n')
		{
			cities_.push_back(tempReadVector); 
			tempReadVector = std::vector<unsigned>();
			actualCity++;
		}
	}
}
