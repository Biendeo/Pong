#pragma once
#include <ctime>
#include "Paddle.h"
#include "Ball.h"

enum control {
	NONE,
	UP,
	DOWN,
	CONFIRM,
	CANCEL
};

class Pong {

	public:
	Pong();
	~Pong();
	void Update();
	int GetDrawsPerSecond();
	int GetHeight();
	int GetWidth();
	void RoundWin(int player);
	Paddle *player1;
	Paddle *player2;
	Ball *ball;

	private:
	int drawsPerSecond; // CONST
	double deltaTime;
	double frameTime;
	clock_t lastUpdate;
	int height;
	int width;
};

