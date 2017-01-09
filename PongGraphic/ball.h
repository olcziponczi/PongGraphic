#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Ball{

private:
	Vector2f position;

	// A RectangleShape object called ref
	RectangleShape ballShape;

	float xVelocity = .2f;
	float yVelocity = .2f;
	

public:
	Ball(float startX, float startY);

	FloatRect getPosition();

	RectangleShape getShape();

	float getXVelocity();

	void reboundSides();

	void reboundBat();

	void hitBottom();

	void hitTop();

	void restartBall();

	void update();

	void addPointA();

	void showPointsA();

	void showPointsB();

	void addPointB();

	int lives = 3;
	
	int lives2 = 3;
};