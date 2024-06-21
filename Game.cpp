#include "Game.h"
#include "colors.h"
#include <iostream>
#include <stdlib.h> // clear of console

#include <random>

int GetRandomNumber(int min, int max)     //Создаём random_device. На его основе создаём mt19937_64.На его основе создаём уже генератор dis, такой, чтоб он генерировал от min до max. И уже этот генератор можно вызывать несколько раз в виде dis(gen). Но в коде выше он вызывается только один раз.
{
	auto rnd = std::random_device{};
	auto gen = std::mt19937_64{ rnd() };
	auto dis = std::uniform_int_distribution<int>{ min, max };
	return dis(gen);
}

static int transformations(const std::string& str)
{
	if (str == "A" || str == "a")
		return 0;
	else if (str == "B" || str == "b")
		return 1;
	else if (str == "C" || str == "c")
		return 2;
	else if (str == "D" || str == "d")
		return 3;
	else if (str == "E" || str == "e")
		return 4;
	/*else if (str == "F" || str == "f")
		return 5;
	else if (str == "G" || str == "g")
		return 6;
	else if (str == "H" || str == "h")
		return 1;
	else if (str == "I" || str == "i")
		return 1;
	else if (str == "J" || str == "j")
		return 1;*/
	else 
		return -1;

}

static int transformations(int num)
{
	if (num > 5 && num < 1)
		return -1;
	else
		return num - 1;
}

void Game::restart()
{
	std::cout << "You want try again? Write 1 if you want and 0 if not.";
	int will_restart;
	std::cin >> will_restart;
	if (will_restart == 1)
	{
		game_ended = false;
		move_player_ai = false;
		who_win = "AI_BOT";
		run();
	}
	else
	{
		std::cout << "GOODBYE!" << std::endl;
	}
}

void Game::run() //запуск игры
{
	welcome();
	create_player();
	add_ships();
	create_ai();
	add_ships_ai();
	battle();

}

void Game::welcome()
{
	std::cout << "Welcome to <Sea of the battle>!" << std::endl;
}

void Game::create_player()
{
	std::cout << "Please, write your name!" << std::endl;
	std::string nickname;
	std::cin >> nickname;
	player1 = Player(nickname);
}

void Game::add_ships()
{
	int count = player1.N;
	//int size;
	std::string x_old;
	int x;
	int y;
	//std::string rotation;
	while (count > 0)
	{
		std::cout << "Please, write size of ship(1, 2, 3, 4), coordinates(x and y) and rotation(down or right). For example <1 A 5 down>." << std::endl;
		//std::cin >> size >> x_old >> y >> rotation;
		std::cin >> x_old >> y;
		y = transformations(y);
		x = y;
		y = transformations(x_old);
		//y = transformations(y);

		//if (player1.get_my_field().check_places(x, y, size, rotation) == true)
		if (player1.get_my_field().check_places(x, y) == true)
		{
			//player1.fill_my_flot(x, y, size, rotation);
			player1.fill_my_flot(x, y);
		}
		--count;
		system("cls");
		player1.get_my_field().draw_field();
	}
}



//void Game::mode_game()
//{
//	Colors color;
//	
//	color.set_color(CL_CYAN);
//
//	std::cout << "What mode you want: against AI(1) or Against another player(2) ?" << std::endl;
//
//}

void Game::step_player() // ход игрока
{
	int x;
	int y;
	std::string x_old;
	std::cout << "Write powition for attack! For example,  <a 3> or <B 5> . " << std::endl;
	std::cin >> x_old >> y;
	x = transformations(x_old);
	y = transformations(y);
	if (x != -1 && y != -1)
	{
		player_attack(x, y);
		system("cls");
		player1.get_enemy_field().draw_field();
		player1.get_my_field().draw_field();
	}
}

void Game::step_player_ai()
{
	int x = GetRandomNumber(0, 5);
	int y = GetRandomNumber(0, 5);
	ai_attack(x, y);
}

void Game::end_game()
{
	if (who_win == "AI_BOT")
	{
		std::cout << "You lose, AI_BOT win! You can try again:)";
	}
	else
	{
		std::cout << "You win, AI_BOT lose! You can try again:)";
	}
	restart();
}

void Game::create_ai()
{
	player_ai = Player("AI_BOT");
}

void Game::add_ships_ai()
{
	int count = player_ai.N;
	int n = player_ai.N;
	int size;
	int x;
	int y;
	std::string rotation;
	while (count > 0)
	{
		size = 1;
		if (GetRandomNumber(0, 1) == 1)
			rotation = "down";
		else
			rotation = "right";
		x = GetRandomNumber(0, n);
		y = GetRandomNumber(0, n);
		/*if (player_ai.get_my_field().check_places(x, y, size, rotation) == true)
		{
			player_ai.fill_my_flot(x, y, size, rotation);
		}*/
		if (player_ai.get_my_field().check_places(x, y) == true)
		{
			player_ai.fill_my_flot(x, y);
		}
		count--;  
	}
}

void Game::battle()
{

	while (game_ended == false)
	{
		if (move_player_ai == false)
		{
			step_player();
		}
		else
		{
			step_player_ai();
		}
	}
	end_game();
}

void Game::player_attack(const int x, const int y)
{
	if (player_ai.get_my_field().check_attack(x, y) == true)
	{
		player_ai.fill_my_flot(x, y);
		player1.fill_enemy_flot(x, y, -2);
		player_ai.reduce_lifes();
		if (player_ai.losed() == true)
		{
			game_ended = true;
			who_win = player1.get_name();
		}
	}
	else
	{
		player1.fill_enemy_flot(x, y, -1);
		player_ai.kill_my_void(x, y);
		move_player_ai = true;
	}
}

void Game::ai_attack(const int x, const int y)
{
	if (player1.get_my_field().check_attack(x, y) == true)
	{
		player1.kill_my_flot(x, y);
		player1.reduce_lifes();
		if (player1.losed() == true)
		{
			game_ended = true;
		}
	}
	else
	{
		player1.kill_my_void(x, y);
		move_player_ai = false;
	}
}
