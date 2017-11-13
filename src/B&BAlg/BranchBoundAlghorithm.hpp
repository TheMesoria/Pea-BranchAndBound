#pragma once

#include <optional>
#include <list>

class BranchBoundAlghorithm
{
	const CityMap* map_;
	CityMap::Path bestPath_;

	const unsigned& getDistance(CityMap::Path &path);
	std::optional<bool> execute(CityMap::Path current, std::list <unsigned>& citiesLeft);
	std::optional<bool> handle(CityMap::Path current, std::list<unsigned>& citiesLeft);
public:
	BranchBoundAlghorithm(const CityMap& map, const CityMap::Path& bestPath);
	~BranchBoundAlghorithm() = default;
	
	std::optional<bool> start();
	const CityMap::Path& getResult() const { return bestPath_; };
	
	
	BranchBoundAlghorithm& operator=(const BranchBoundAlghorithm) = delete;
	BranchBoundAlghorithm& operator()(const BranchBoundAlghorithm) = delete;
	BranchBoundAlghorithm& operator+=(const BranchBoundAlghorithm) = delete;
	BranchBoundAlghorithm& operator-=(const BranchBoundAlghorithm) = delete;
	BranchBoundAlghorithm& operator*=(const BranchBoundAlghorithm) = delete;
	BranchBoundAlghorithm& operator/=(const BranchBoundAlghorithm) = delete;
	bool operator==(const BranchBoundAlghorithm) = delete;
	bool operator!=(const BranchBoundAlghorithm) = delete;
	bool operator<(const BranchBoundAlghorithm) = delete;
	bool operator>(const BranchBoundAlghorithm) = delete;
	bool operator>=(const BranchBoundAlghorithm) = delete;
	bool operator<=(const BranchBoundAlghorithm) = delete;
};