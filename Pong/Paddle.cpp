#include "Paddle.h"
#include "Pong.h"
#include "AI.h"
#include "rlutil.h"

Paddle::Paddle(Pong *g, int x, AIMode ai) {
	this->g = g;
	this->x = x;
	width = 5;
	Reset();
	score = 0;
	this->ai = new AI(g, this, ai);
}


Paddle::~Paddle() {
	delete ai;
}


void Paddle::Update() {
	/// This aligns the cursor in the proper spot at the beginning.
	if (y < -1) {
		y = ((this->g->GetHeight() - width) / 2);
		for (int i = 0; i < width; i++) {
			rlutil::locate(x, y + i);
			rlutil::setChar('|');
		}
	}

	ai->Update();

	switch (nextPress) {
		case Control::UP:
			--y;
			if (y < 0) {
				++y;
			} else {
				rlutil::locate(x, y + width);
				rlutil::setChar(' ');
				rlutil::locate(x, y);
				rlutil::setChar('|');
			}
			break;
		case Control::DOWN:
			++y;
			if (y > g->GetHeight() - width) {
				--y;
			} else {
				rlutil::locate(x, y - 1);
				rlutil::setChar(' ');
				rlutil::locate(x, y + width - 1);
				rlutil::setChar('|');
			}
			break;
	}
	nextPress = Control::NONE;

	std::cout.flush();
}


int Paddle::GetUpperBound() {
	return y;
}

int Paddle::GetMiddle() {
	return y + (width / 2) - 1;
}

int Paddle::GetLowerBound() {
	return y + width - 1;
}


int Paddle::GetX() {
	return x;
}

void Paddle::Reset() {
	y = -5;
	nextPress = Control::NONE;
}


int Paddle::GetWidth() {
	return width;
}

AIMode Paddle::GetAIMode() {
	return ai->GetMode();
}