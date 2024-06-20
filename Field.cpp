#include "Field.h"
#include <iostream>
#include "colors.h"

Field::Field(const std::string& new_name)
{
	name = new_name;
}

void Field::draw_field()
{
	//Colors color;

	color.set_color(CL_YELLOW);

	std::cout << "   " << name << std::endl;

	//std::cout << std::endl;


	color.set_color(CL_GREEN);
	//std::cout << "  |A|B|C|D|E|F|G|H|I|J|" << std::endl;
	std::cout << "  |A|B|C|D|E|F|G|" << std::endl;
	//std::cout << "-------------" << std::endl;
	for (int i = 0; i < size; i++)
	{
		color.set_color(CL_GRAY);
		if (i != 6) // was 9
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

void Field::add_ship(const int x, const int y, const int type, const std::string& rotation) // rotaion  может быть вниз или вправо.
{

	if (map[x][y] != 0)
	{
		color.set_color(CL_RED);
		std::cout << "Can't put here!" << std::endl;
	}

	if (type == 1)
	{
		map[x][y] = 1;
	}
	else
	{
		color.set_color(CL_RED);
		std::cout << "Error of type ship!" << std::endl;
	}
	

}
