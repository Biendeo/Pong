#include "Pong.h"
#include "rlutil.h"

#ifdef WIN32
#include <Windows.h>
#endif


Pong::Pong() {
	// TODO: Make this modifiable.
	drawsPerSecond = 100;
	deltaTime = 0.0;
	frameTime = 0.0;
	lastUpdate = clock();
	height = rlutil::trows();
	width = rlutil::tcols();
	player1 = new Paddle(this, 2);
	player2 = new Paddle(this, rlutil::tcols() - 1);
	ball = new Ball(this);
}


Pong::~Pong() {
	delete(player1);
	delete(player2);
	delete(ball);
}


void Pong::Update() {
	/// This part calculates time and updates.
	clock_t beforeUpdate = lastUpdate;
	lastUpdate = clock();
	deltaTime = ((double)(lastUpdate - beforeUpdate) / CLOCKS_PER_SEC);
	frameTime += deltaTime;

	/// This executes when it is time to draw the frame.
	if (frameTime >= ((double)1 / GetDrawsPerSecond())) {
		// TODO: Make it so the game only updates when in-game.
		player1->Update();
		player2->Update();
		ball->Update();

		frameTime -= ((double)1 / GetDrawsPerSecond());
	}

	/// This part processes inputs.
	/*
#ifdef WIN32
	for (int i = 0; i < 256; i++) {
		if (GetAsyncKeyState(i) & 0x8000) {
			switch (i) {
				case 'l':
					std::cout << GetAsyncKeyState(i);
					player1->nextPress = control::UP;
					break;
				case '.':
					std::cout << GetAsyncKeyState(i);
					player1->nextPress = control::DOWN;
					break;
				case 'a':
					std::cout << GetAsyncKeyState(i);
					player2->nextPress = control::UP;
					break;
				case 'z':
					std::cout << GetAsyncKeyState(i);
					player2->nextPress = control::DOWN;
					break;
			}
		}
	}
#else*/
	rlutil::key keyPress = rlutil::nb_getch();
	switch (keyPress) {
		case 'a':
			player1->nextPress = UP;
			break;
		case 'z':
			player1->nextPress = DOWN;
			break;
		case 'l':
			player2->nextPress = UP;
			break;
		case '.':
			player2->nextPress = DOWN;
			break;
	}
//#endif
}


int Pong::GetDrawsPerSecond() {
	return drawsPerSecond;
}


int Pong::GetHeight() {
	return height;
}


int Pong::GetWidth() {
	return width;
}


void Pong::RoundWin(int player) {
	if (player == 1) {
		++player1->score;
		rlutil::locate((rlutil::tcols() / 2) - 7, 3);
		std::cout << "Player 1 wins!";
	} else if (player == 2) {
		++player2->score;
		rlutil::locate((rlutil::tcols() / 2) - 7, 3);
		std::cout << "Player 2 wins!";
	}

	rlutil::locate((rlutil::tcols() / 2) - 2, 5);
	std::cout << player1->score;
	rlutil::locate((rlutil::tcols() / 2) + 1, 5);
	std::cout << player2->score;

	rlutil::msleep(3000);

	ball->Reset();
	player1->Reset();
	player2->Reset();

	rlutil::cls();
}
