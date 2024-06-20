#include <iostream>
#include "Field.h"

int main()
{
	Field a("ENEMY_SHIPS");
	a.draw_field();

	Field b("MY_SHIPS");
	b.draw_field();

	a.add_ship(0 , 0, 1, "o");

	a.draw_field();

	/*while (true)
	{
		a.draw_field();
		a.add_ship();
		a.draw_field();
	}*/


	return 1;
}