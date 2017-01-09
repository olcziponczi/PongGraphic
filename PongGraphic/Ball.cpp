#include "stdafx.h"
#include "Ball.h"
#include <iostream>

Ball::Ball(float startX, float startY){
	position.x = startX;
	position.y = startY;

	ballShape.setSize(sf::Vector2f(10, 10));
	ballShape.setPosition(position);
}

FloatRect Ball::getPosition(){
	return ballShape.getGlobalBounds();
}

RectangleShape Ball::getShape(){
	return ballShape;
}

float Ball::getXVelocity(){
	return xVelocity;
}

void Ball::reboundSides(){
	yVelocity = -yVelocity;
}

void Ball::reboundBat(){
	position.x -= (xVelocity * 30);
	xVelocity = -xVelocity;
}

void Ball::hitBottom(){
	position.y = 1;
	position.x = 500;
}
void Ball::hitTop() {
	position.y = 500;
	position.x = 1;
 }

void Ball::update(){
	// Update the ball position variables
	position.y += yVelocity;
	position.x += xVelocity;

	// Move the ball and the bat
	ballShape.setPosition(position);
}

void Ball::restartBall() {
	position.y = 380;
	position.x = 500;
}

void Ball::addPointA() {
	lives++;
	lives2--;
	
}
void Ball::showPointsA() {
	std::cout << lives;
}

void Ball::showPointsB() {
	std::cout << lives2;
}
void Ball::addPointB() {
	lives2++;
	lives--;

}