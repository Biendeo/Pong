#include "Paddle.h"
#include "Pong.h"
#include "rlutil.h"

Paddle::Paddle(Pong *g, int x) {
	this->g = g;
	this->x = x;
	width = 5;
	Reset();
	score = 0;
}


Paddle::~Paddle() {

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

	switch (nextPress) {
		case UP:
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
		case DOWN:
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
	nextPress = NONE;

	std::cout.flush();
}


int Paddle::GetUpperBound() {
	return y;
}


int Paddle::GetLowerBound() {
	return y + width - 1;
}


int Paddle::GetX() {
	return x;
}


void Paddle::Reset() {
	y = -5;
	nextPress = NONE;
}


int Paddle::GetWidth() {
	return width;
}
