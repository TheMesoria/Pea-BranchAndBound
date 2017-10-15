#pragma once
#include <string>
#include <vector>
#include <fstream>

class CityMap
{
public:
	struct Path;

private:
	std::string source_;
	std::vector<std::vector<unsigned>> cities_;
	std::vector<std::string> cityNames_;

	void LoadToMap(const std::string &fileName);
public:
	CityMap(const std::string &fileName);
	~CityMap();

	void PrintValueTriangle() const;
	const std::vector<std::vector<unsigned>>& getMap() const { return cities_; };

	struct Path
	{
		std::vector<unsigned> cities;
		unsigned length;

		std::string toString() const
		{
			std::string retVal = "";
			for (auto var : cities)
			{
				retVal += std::to_string(var)+"->";
			}
			return retVal;
		}

		Path()
		{
			cities = std::vector<unsigned>();
			length = 0;
		}
	};
};