#include <cmath>
#include "Ball.h"
#include "Pong.h"
#include "rlutil.h"


Ball::Ball(Pong *g) {
	this->g = g;
	Reset();
}


Ball::~Ball() {
}


double Ball::GetVelocityX() {
	return deltaX;
}


double Ball::GetVelocityY() {
	return deltaY;
}


double Ball::GetVelocity() {
	return hypot(deltaX, deltaY);
}


double Ball::GetPositionX() {
	return x;
}


double Ball::GetPositionY() {
	return y;
}


void Ball::Update() {
	const int leftMargin = 3;
	const int rightMargin = 2;
	const int topMargin = 1;
	const int bottomMargin = 1;
	const double speedXIncrease = 0.0001;
	const double speedYIncrease = 0.02;

	if (deltaX > 0) {
		deltaX += speedXIncrease;
	} else if (deltaX < 0) {
		deltaX -= speedXIncrease;
	}

	int oldX = NormalizeX();
	int oldY = NormalizeY();

	x += deltaX;
	y += deltaY;

	if (x <= leftMargin) {
		if (g->player1->GetX() - x < deltaX * -1) {
			if (NormalizeY() >= g->player1->GetUpperBound() && NormalizeY() <= g->player1->GetLowerBound()) {
				x = (2 * leftMargin - x);
				deltaX *= -1;
				deltaY -= (((g->player1->GetLowerBound() - y) - (g->player1->GetWidth() / 2)) * speedYIncrease);
			}
		}
		if (x < 1) {
			g->RoundWin(2);
			return;
		}
	}
	if (x >= g->GetWidth() - rightMargin) {
		if (x - g->player2->GetX() < deltaX) {
			if (NormalizeY() >= g->player2->GetUpperBound() && NormalizeY() <= g->player2->GetLowerBound()) {
				x = (2 * (g->GetWidth() - rightMargin) - x);
				deltaX *= -1;
				deltaY -= (((g->player2->GetLowerBound() - y) - (g->player2->GetWidth() / 2)) * speedYIncrease);
			}
		}
		if (x > g->GetWidth()) {
			g->RoundWin(1);
			return;
		}
	}
	if (y < topMargin) {
		y = (2 * topMargin - y);
		deltaY *= -1;
	}
	if (y >= g->GetHeight() - bottomMargin) {
		y = (2 * (g->GetHeight() - bottomMargin) - y);
		deltaY *= -1;
	}

	if (oldX != NormalizeX() || oldY != NormalizeY()) {
		rlutil::locate(oldX, oldY);
		rlutil::setChar(' ');
		rlutil::locate(NormalizeX(), NormalizeY());
		rlutil::setChar('*');
	}

	std::cout.flush();
}


double Ball::getAngle() {
	return tan(deltaY / deltaX);
}


int Ball::NormalizeX() {
	return (int)round(x);
}


int Ball::NormalizeY() {
	return (int)round(y);
}


void Ball::Reset() {
	x = g->GetWidth() / 2;
	y = g->GetHeight() / 2;
	if (g->player1->score > g->player2->score) {
		deltaX = 0.1;
	} else {
		deltaX = -0.1;
	}
	deltaY = 0.0;
}
