#pragma once
#include "Field.h"
//#include "Ship.h"
#include <vector>
#include <string>


class Player
{
private:

	Field my_ships;
	Field enemy_ships;

	//std::vector<Ship> my_flot;

	int lifes = 5;

	bool moved = false;

	bool lose = false;

	std::string name;

	//Ship saved_ship;

public:

	//Ship& find_ship(const int, const int);

	Player() = default;

	Player(const std::string&);

	Player& operator=(const Player& player);

	std::string get_name() const;

	//std::vector<Ship> get_my_flots();

	void reduce_lifes();

	bool losed() const;

	//void fill_my_flot(const int, const int, const int, const std::string&);

	void fill_my_flot(const int, const int);

	void kill_my_flot(const int, const int);

	void kill_my_void(const int, const int);

	//void init_fields();

	Field& get_my_field();

	Field& get_enemy_field();

	void draw_fields();

	void change_moved();

	static const int N = 5;

	void fill_enemy_flot(const int, const int, const int);
};

