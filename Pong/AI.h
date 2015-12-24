#pragma once
class Pong;
class Paddle;
enum class Control;

enum class AIMode {
	NONE,
	HUMAN,
	EASY,
	NORMAL,
	HARD,
	IMPOSSIBLE
};

class AI {
	public:
	AI(Pong *g, Paddle *p, AIMode mode);
	~AI();
	void Update();
	AIMode GetMode();

	private:
	Pong *g;
	Paddle *p;
	AIMode mode;
	int reactionTime;
	int currentReaction;
	Control ComputeNextAction();
};

