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

	for (auto vec : cities_)
	{
		for (auto var : vec)
		{
			std::cout << var;
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
