#pragma once
#include <array>
#include <string>
#include "colors.h"

class Field
{
private:

	std::string name;

	Colors color;

	static const int size = 7;

	std::array<std::array<int, 7>, 7> map = { 0 };

public:

	Field(const std::string&);

	void draw_field();

	void add_ship(const int, const int, const int, const std::string&);

};

