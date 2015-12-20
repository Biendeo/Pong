#pragma once

class Pong;

namespace rlutil {
	/// This is specifically a keypress. It uses rlutil's key enums.
	typedef int key;
}

class Paddle {
	public:
	Paddle(Pong *g, int x);
	~Paddle();
	void Update();
	rlutil::key nextPress;
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

