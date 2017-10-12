#pragma once
#include <string>
#include <vector>
#include <fstream>

class CityMap
{
	std::string source_;
	std::vector<std::vector<unsigned>> cities_;
	std::vector<std::string> cityNames_;
public:
	CityMap(const std::string& fileName);
	~CityMap();
	
	void PrintValueTriangle() const;

private:
	void LoadToMap(const std::string& fileName);
};