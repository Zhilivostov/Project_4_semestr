#pragma once
#include <vector>
#include <string>


class Ship
{
private:

	std::vector < std::pair <int, int> > locations;

	int hp;

	std::string rotation; // down or right;

	bool flooded = false; // статус затоплен корабль или нет


public:

	Ship() = default;

	Ship(const int, const int, const int, const std::string&);

	void add_location(const int, const int);

	void reduce_hp();

	void change_status();

	std::vector < std::pair <int, int> > get_locations();

	bool is_flooded() const;
};

