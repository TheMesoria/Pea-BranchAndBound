#include "Map.hpp"
#include <iostream>

CityMap::CityMap(const std::vector<std::vector<float>>& pointVector)
{
	for (auto i = 0u; i < pointVector.size(); i++)
	{
		std::vector<unsigned> tmp;
		for (auto j = 0u; j < pointVector.size(); j++)
		{
			float firstX = pointVector[i][0], firstY=pointVector[i][1];
			float secondX = pointVector[j][0], secondY = pointVector[j][1];

			auto resultX = abs(firstX - secondX), resultY=abs(firstY-secondY);
			auto res = sqrt(pow(resultX, 2) + pow(resultY, 2));
			unsigned resU = ceil(res);
			tmp.push_back(resU);
		}
		cities_.push_back(tmp);
		tmp.clear();
	}
}

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
