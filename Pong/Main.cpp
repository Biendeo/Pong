#include <iostream>
#include "rlutil.h"
#include "Pong.h"
#include "AI.h"

int main() {
	rlutil::hidecursor();
	rlutil::cls();

	bool valid = false;

	AIMode ai1;
	std::cout << "Player 1 mode:" << std::endl;
	std::cout << "R - Human" << std::endl;
	std::cout << "D - No Movement" << std::endl;
	std::cout << "E - Easy AI" << std::endl;
	std::cout << "N - Normal AI" << std::endl;
	std::cout << "H - Hard AI" << std::endl;
	std::cout << "I - Impossible AI" << std::endl;


	while (valid == false) {
		char input = rlutil::getkey();
		switch (input) {
			case 'r':
			case 'R':
				ai1 = AIMode::HUMAN;
				valid = true;
				break;
			case 'd':
			case 'D':
				ai1 = AIMode::NONE;
				valid = true;
				break;
			case 'e':
			case 'E':
				ai1 = AIMode::EASY;
				valid = true;
				break;
			case 'n':
			case 'N':
				ai1 = AIMode::NORMAL;
				valid = true;
				break;
			case 'h':
			case 'H':
				ai1 = AIMode::HARD;
				valid = true;
				break;
			case 'i':
			case 'I':
				ai1 = AIMode::IMPOSSIBLE;
				valid = true;
				break;
		}
	}

	rlutil::cls();
	valid = false;

	AIMode ai2;
	std::cout << "Player 2 mode:" << std::endl;
	std::cout << "R - Human" << std::endl;
	std::cout << "D - No Movement" << std::endl;
	std::cout << "E - Easy AI" << std::endl;
	std::cout << "N - Normal AI" << std::endl;
	std::cout << "H - Hard AI" << std::endl;
	std::cout << "I - Impossible AI" << std::endl;


	while (valid == false) {
		char input = rlutil::getkey();
		switch (input) {
			case 'r':
			case 'R':
				ai2 = AIMode::HUMAN;
				valid = true;
				break;
			case 'd':
			case 'D':
				ai2 = AIMode::NONE;
				valid = true;
				break;
			case 'e':
			case 'E':
				ai2 = AIMode::EASY;
				valid = true;
				break;
			case 'n':
			case 'N':
				ai2 = AIMode::NORMAL;
				valid = true;
				break;
			case 'h':
			case 'H':
				ai2 = AIMode::HARD;
				valid = true;
				break;
			case 'i':
			case 'I':
				ai2 = AIMode::IMPOSSIBLE;
				valid = true;
				break;
		}
	}

	rlutil::cls();


	int pointLimit;
	std::cout << "Point limit:" << std::endl;
	std::cout << "1 - 5 points" << std::endl;
	std::cout << "2 - 10 points" << std::endl;
	std::cout << "3 - 20 points" << std::endl;
	std::cout << "4 - 30 points" << std::endl;
	valid = false;

	while (valid == false) {
		char input = rlutil::getkey();
		switch (input) {
			case '1':
				pointLimit = 5;
				valid = true;
				break;
			case '2':
				pointLimit = 10;
				valid = true;
				break;
			case '3':
				pointLimit = 20;
				valid = true;
				break;
			case '4':
				pointLimit = 30;
				valid = true;
				break;
		}
	}


	rlutil::cls();

	Pong *g = new Pong(pointLimit, ai1, ai2);

	
	while (!g->GetWinState()) {
		g->Update();
	}

	delete g;

	return EXIT_SUCCESS;
}