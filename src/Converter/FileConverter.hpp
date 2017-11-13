#include <list>
#include <string>
#include <memory>
#include "../City/Map.hpp"

class FileConverter{
public:
	const static std::vector<std::vector<float>> parsePoints(const std::string& path);

	CityMap getCities(const std::list<std::list<unsigned>> &data);
	CityMap getCities(const std::string &path);
};