#include "stdafx.h"
#include "Bat2.h"

Bat2::Bat2(float startX, float startY)
{
	position2.x = startX;
	position2.y = startY;

	batShape2.setSize(sf::Vector2f(10, 100));
	batShape2.setPosition(position2);
}

FloatRect Bat2::getPosition() {
	return batShape2.getGlobalBounds();
}

RectangleShape Bat2::getShape() {
	return batShape2;
}

void Bat2::moveLeft() {
	position2.y -= batSpeed2;
}

void Bat2::moveRight() {
	position2.y += batSpeed2;
}

void Bat2::update() {
	batShape2.setPosition(position2);
}
