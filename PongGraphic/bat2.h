#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Bat2
{
private:
	Vector2f position2;

	// A RectangleShape object
	RectangleShape batShape2;

	float batSpeed2 = .3f;

public:
	Bat2(float startX, float startY);

	FloatRect getPosition();

	RectangleShape getShape();

	void moveLeft();

	void moveRight();

	void update();

};