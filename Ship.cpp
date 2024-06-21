#include "Ship.h"

Ship::Ship(const int new_hp, const int x, const int y, const std::string& new_rotation)
{
	hp = new_hp;
	rotation = new_rotation;
	locations.push_back(std::make_pair(x, y));
}

void Ship::add_location(const int x, const int y)
{
	locations.push_back(std::make_pair(x, y));
}

void Ship::reduce_hp()
{
	hp--;
	if (hp == 0)
		flooded = true;
}

std::vector<std::pair<int, int>> Ship::get_locations()
{
	return locations;
}

bool Ship::is_flooded() const
{
	return flooded;
}

void Ship::change_status()
{
	if (flooded == false)
		flooded = true;
	else
		flooded = false;
}
