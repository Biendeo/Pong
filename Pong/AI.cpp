#include "AI.h"
#include "Ball.h"
#include "Paddle.h"
#include "Pong.h"
#include <cmath>


AI::AI(Pong *g, Paddle *p, AIMode mode) {
	this->g = g;
	this->p = p;
	this->mode = mode;
	switch (mode) {
		case AIMode::EASY:
			reactionTime = 10;
			break;
		case AIMode::NORMAL:
			reactionTime = 5;
			break;
		case AIMode::HARD:
			reactionTime = 3;
			break;
		case AIMode::IMPOSSIBLE:
			reactionTime = 1;
			break;
		default:
			reactionTime = 50;
			break;
	}
	currentReaction = 0;
}


AI::~AI() {
}


void AI::Update() {
	if (mode != AIMode::HUMAN && mode != AIMode::NONE) {
		++currentReaction;
		if (currentReaction >= reactionTime) {
			p->nextPress = ComputeNextAction();
			currentReaction -= reactionTime;
		}
	}
}

AIMode AI::GetMode() {
	return mode;
}

Control AI::ComputeNextAction() {
	switch (mode) {
		case AIMode::EASY:
		case AIMode::NORMAL:
		case AIMode::HARD:
		case AIMode::IMPOSSIBLE:
			if (abs(g->ball->GetPositionY() - p->GetMiddle()) < 0.5) {
				return Control::NONE;
			} else if (g->ball->GetPositionY() < p->GetMiddle()) {
				return Control::UP;
			} else if (g->ball->GetPositionY() > p->GetMiddle()) {
				return Control::DOWN;
			} else {
				/// This is in case it goes wrong.
				return Control::NONE;
			}
		// TODO: Make a more challenging and smarter AI that predicts where the ball will reach.
		default:
			return Control::NONE;
	}
}
