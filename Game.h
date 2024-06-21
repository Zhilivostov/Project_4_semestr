#pragma once
#include "Player.h"


class Game
{
private:
	
	bool game_ended = false;

	Player player1;

	Player player_ai;

	bool move_player_ai = false;

	//mode;

	std::string who_win = "AI_BOT";

public:

	Game() = default;

	void restart();

	void run();

	void welcome();

	void create_player();

	void add_ships();

	//void mode_game();

	void step_player();

	void step_player_ai();

	void end_game();

	void create_ai();

	void add_ships_ai();

	void battle();

	void player_attack(const int, const int);

	void ai_attack(const int, const int);

};

