#pragma once
#include "Field.h"
#include "Ship.h"
#include <array>


class Player
{
private:

	Field my_ships;
	Field enemy_ships;

	std::array<Ship, 10> my_flot;

	bool moved = false;

public:

	void fill_my_flot(const Ship);

	void init_fields();


};

