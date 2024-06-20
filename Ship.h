#pragma once
#include <vector>


class Ship
{
private:

	std::vector < std::pair <int, int> > locations;

	int hp;

	bool flooded = false; // статус затоплен корабль или нет


public:

	Ship(const int);

	void add_location(const int, const int);

	void reduce_hp();
};

