#include "Player.h"
#include <string>

//Ship& Player::find_ship(const int x, const int y)
//{
//	for (auto& item : my_flot)
//	{
//		for (auto& place : item.get_locations())
//		{
//			if (place.first == x && place.second == y)
//			{
//				item.reduce_hp();
//				if (item.is_flooded() == true)
//				{
//					
//
//				}
//			}
//			
//		}
//	}
//}

Player::Player(const std::string& new_name):
	name(new_name), my_ships(Field("MY_SHIPS")), enemy_ships(Field("RADAR"))
{
	/*int count = lifes;
	while (count > 0)
	{

	}*/
}

Player& Player::operator=(const Player& player)
{
	my_ships = player.my_ships;
	enemy_ships = player.enemy_ships;
	//my_flot = player.my_flot;
	name = player.name;
	return *this;
}

std::string Player::get_name() const
{
	return name;
}

//std::vector<Ship> Player::get_my_flots()
//{
//	return my_flot;
//}

void Player::reduce_lifes()
{
	lifes--;
	if (lifes == 0)
		lose = true;
}

bool Player::losed() const
{
	return lose;
}

//void Player::fill_my_flot(const int x, const int y, const int type, const std::string& rotation)
void Player::fill_my_flot(const int x, const int y)
{
	//my_ships.add_ship(x, y, type, rotation);
	my_ships.add_ship(x, y);
	//my_flot.push_back(Ship(x, y, type, rotation));
}

void Player::kill_my_flot(const int x, const int y)
{
	my_ships.kill_ship(x, y);
}

void Player::kill_my_void(const int x, const int y)
{
	my_ships.kill_void(x, y);
}

//void Player::init_fields()
//{
//	my_ships = Field("my_field");
//	enemy_ships = Field("enemy_field");
//}

Field& Player::get_my_field()
{
	return my_ships;
}

Field& Player::get_enemy_field()
{
	return enemy_ships;
}

void Player::draw_fields()
{
	enemy_ships.draw_field();
	my_ships.draw_field();

}

void Player::change_moved()
{
	if (moved == true)
		moved = false;
	else
		moved = true;
}

void Player::fill_enemy_flot(const int x, const int y, const int type)
{
	if (type == -1)
	{
		enemy_ships.kill_void(x, y);
	}
	else
	{
		enemy_ships.kill_ship(x, y);
	}
	
}
