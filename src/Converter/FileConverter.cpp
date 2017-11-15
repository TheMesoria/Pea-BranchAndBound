#include <list>
#include <iostream>
#include <fstream>
#include "FileConverter.hpp"

const std::vector<std::vector<float>> FileConverter::parsePoints(const std::string & path)
{
	std::vector<std::vector<float>> points;
	std::string tmp;

	std::fstream file(path, std::ios::in);


	while ( tmp != "NODE_COORD_SECTION") 
	{
		std::getline(file, tmp);
	}

	std::string name;
	float x, y;
	while (true)
	{
		file >> name >> x >> y;
		if (name == "EOF") break;
		points.push_back(std::vector<float>());
		points.back().push_back(x);
		points.back().push_back(y);
	}

	return points;
}