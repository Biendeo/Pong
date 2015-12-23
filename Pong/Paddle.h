#pragma once

class Pong;

enum class AIMode {
	NONE,
	HUMAN,
	EASY,
	NORMAL,
	HARD,
	IMPOSSIBLE
};

class Paddle {
	public:
	Paddle(Pong *g, int x);
	~Paddle();
	void Update();
	Control nextPress;
	int GetUpperBound();
	int GetLowerBound();
	int score;
	int GetX();
	int GetWidth();
	void Reset();

	private:
	Pong *g;
	int width; // CONST
	int x;
	int y;
};

