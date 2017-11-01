#include "stdafx.h"
#include "Ball.h"
#include <iostream>


Ball::Ball(float startX, float startY){
	position.x = startX;
	position.y = startY;

	ballShape.setSize(sf::Vector2f(15, 15));
	ballShape.setPosition(position);

	this->player.playMusic();
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

void Ball::reboundSides(){		//odbicie od krawêdzi
	
	yVelocity = -yVelocity;
	this->player.playFart();
}

void Ball::reboundBat(){			//odbicie od paletki
	position.x -= (xVelocity * 30);
	xVelocity = -xVelocity;
	this->player.playFart();
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
	position.y += yVelocity;		//aktualizacja pozycji
	position.x += xVelocity;
	ballShape.setPosition(position);	//poruszanie siê pi³ki
}

void Ball::restartBall() {				//pocz¹tkowe coordy pi³ki
	position.y = 380;
	position.x = 500;
}

void Ball::addPointA() {
	lives++;
	
}
void Ball::showPointsA() {
	std::cout << lives;
}

void Ball::showPointsB() {
	std::cout << lives2;
}
void Ball::addPointB() {
	lives2++;

}