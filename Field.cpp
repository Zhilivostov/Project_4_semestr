#include "Field.h"
#include <iostream>
#include "colors.h"

Field::Field(const std::string& new_name)
{
	name = new_name;
}

void Field::draw_field()
{
	Colors color;

	color.set_color(CL_YELLOW);

	std::cout << "   " << name << std::endl;

	//std::cout << std::endl;


	color.set_color(CL_GREEN);
	//std::cout << "  |A|B|C|D|E|F|G|H|I|J|" << std::endl;
	std::cout << "  |A|B|C|D|E|" << std::endl;
	//std::cout << "-------------" << std::endl;
	for (int i = 0; i < size; i++)
	{
		color.set_color(CL_GRAY);
		if (i != 4) // was 9
			std::cout << " " << i + 1 << "|";
		else
			//std::cout << i + 1 << "|";
			std::cout << " " << i + 1 << "|";
		for (int j = 0; j < size; j++)
		{
			color.set_color(CL_BLUE);
			if (map[i][j] != 0)
			{
				color.set_color(CL_PURPLE);
				std::cout << map[i][j];
				//std::cout << "#";
			}
			else
				std::cout << map[i][j];
			color.set_color(CL_GRAY);
			std::cout << "|";
		}
		std::cout << std::endl;
		//color.clear_all();
	}
}

//void Field::add_ship(const int x, const int y, const int type, const std::string& rotation) // rotaion  может быть вниз или вправо.
void Field::add_ship(const int x, const int y)
{
	Colors color;

	if (map[x][y] != 0)
	{
		color.set_color(CL_RED);
		std::cout << "Can't put here!" << std::endl;
	}

	map[x][y] = 1;

	/*if (type == 1)
	{
		map[x][y] = 1;
	}
	else
	{
		color.set_color(CL_RED);
		std::cout << "Error of type ship!" << std::endl;
	}*/
	

}

//bool Field::check_places(const int x, const int y, const int type, const std::string& rotation)
bool Field::check_places(const int x, const int y)
{
	if (map[x][y] == 0)
		return true;
	return false;
}

bool Field::check_attack(const int x, const int y)
{
	if (map[x][y] == 1)
		return true;
	return false;
}

void Field::kill_ship(const int x, const int y)
{
	map[x][y] = -2;
}

void Field::kill_void(const int x, const int y)
{
	map[x][y] = -1;
}
