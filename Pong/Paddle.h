#pragma once

enum class AIMode;

class Pong;
class AI;

enum class Control {
	NONE,
	UP,
	DOWN,
	CONFIRM,
	CANCEL
};

class Paddle {
	public:
	Paddle(Pong *g, int x, AIMode ai);
	~Paddle();
	void Update();
	Control nextPress;
	int GetUpperBound();
	int GetMiddle();
	int GetLowerBound();
	int score;
	int GetX();
	int GetWidth();
	void Reset();
	AIMode GetAIMode();

	private:
	Pong *g;
	int width; // CONST
	int x;
	int y;
	AI *ai;
};

