//	PEA-Ormaniec-Branch&Bound
//	Created by Ormaniec
//	At 10/7/2017
//	All rights reserved
//

#include <string>
#include <iostream>
#include "City/Map.hpp"

int main(int argc, char *args[])
{
	system("cd");

	std::cout << "Start:\n";
	CityMap map("map.txt");
	map.PrintValueTriangle();
	std::cout << "End\n";
	system("pause");
	return EXIT_SUCCESS;
}