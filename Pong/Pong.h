#pragma once
#include <ctime>

class Paddle;
class Ball;
enum class AIMode;


class Pong {

	public:
	Pong(int pointLimit, AIMode ai1, AIMode ai2);
	~Pong();
	void Update();
	int GetDrawsPerSecond();
	int GetHeight();
	int GetWidth();
	void RoundWin(int player);
	Paddle *player1;
	Paddle *player2;
	Ball *ball;
	bool GetWinState();

	private:
	int drawsPerSecond; // CONST
	double deltaTime;
	double frameTime;
	clock_t lastUpdate;
	int height;
	int width;
	int pointLimit;
};