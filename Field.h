#pragma once
#include <array>
#include <string>
#include "colors.h"

class Field
{
private:

	std::string name;

	//Colors color;

	static const int size = 5;

	std::array<std::array<int, 5>, 5> map = { 0 };

public:
	
	Field() = default;
	Field(const std::string&);

	void draw_field();

	//void add_ship(const int, const int, const int, const std::string&);

	void add_ship(const int, const int);

	//bool check_places(const int, const int, const int, const std::string&);

	bool check_places(const int, const int);

	bool check_attack(const int, const int);

	void kill_ship(const int, const int);

	void kill_void(const int, const int);
};

