#pragma once
class Game
{
private:
	
	bool game_ended = true;




public:

	void run();

	void step_player();

	void end_game();

};

