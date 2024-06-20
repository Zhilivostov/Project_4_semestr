#include "Ship.h"

Ship::Ship(const int new_hp)
{
	hp = new_hp;
}

void Ship::add_location(const int x, const int y)
{
	locations.push_back(std::make_pair(x, y));
}

void Ship::reduce_hp()
{
	hp--;
}
