#pragma once
#include <string>
#include <vector>
#include <list>
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
	CityMap(const std::vector<std::vector<float>>& pointVector);
	CityMap(const std::string &fileName);
	~CityMap();

	void PrintValueTriangle() const;
	const std::vector<std::vector<unsigned>>& getMap() const { return cities_; };

	struct Path
	{
		std::list<unsigned> cities;
		std::list<unsigned> paths;
		unsigned length;

		std::string toString() const
		{
			std::string retVal = "Cities:";
			for (auto var : cities)
			{
				retVal += std::to_string(var)+"->";
			}
			retVal += "\nPaths: ";
			for (auto var : paths)
			{
				retVal += std::to_string(var) + "->";
			}
			retVal += "\nLength: " + std::to_string(length);
			return retVal;
		}

		Path()
		{
			cities = std::list<unsigned>();
			length = 0;
		}
		Path(unsigned length2)
		{
			cities = std::list<unsigned>();
			length = length2;
		}
		void operator=(Path rhs)
		{
			cities = rhs.cities;
			paths = rhs.paths;
			length = rhs.length;
		}
	};
};