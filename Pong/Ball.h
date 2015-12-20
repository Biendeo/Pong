#pragma once
class Pong;

class Ball {
	public:
	Ball(Pong *g);
	~Ball();
	void Update();
	double GetVelocityX();
	double GetVelocityY();
	double GetVelocity();
	double GetPositionX();
	double GetPositionY();
	double getAngle();
	int NormalizeX();
	int NormalizeY();
	void Reset();

	private:
	Pong *g;
	double x;
	double y;
	double deltaX;
	double deltaY;
};

