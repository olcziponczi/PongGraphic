#include "stdafx.h"
#include "bat.h"
#include "bat2.h"
#include "ball.h"
#include "menu.h"
#include <sstream>
#include <cstdlib>

#include <SFML/Graphics.hpp>
using namespace sf;

int main() {
	int windowWidth = 1024;
	int windowHeight = 768;

	RenderWindow window(VideoMode(windowWidth, windowHeight), "Pong");

	// create a bat
	Bat bat(windowWidth - 20, windowHeight / 2);
	Bat2 bat2(windowWidth - 1004, windowHeight /2);
	// create a ball
	Ball ball(windowWidth / 2, 1);
	// Create a "Text" object called "message". 
	Text hud;

	Font font;
	font.loadFromFile("font.ttf");

	// Set the font to our message
	hud.setFont(font);

	// Make it really big
	hud.setCharacterSize(75);

	// Choose a color
	hud.setFillColor(sf::Color::White);

	// This "while" loop goes round and round- perhaps forever
	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)	//spr. czy ktoœ nie zamkn¹³ okna
				window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Up)){
			bat.moveLeft();
		}
		if (Keyboard::isKeyPressed(Keyboard::Down)){
			
			bat.moveRight();
		}
		if (Keyboard::isKeyPressed(Keyboard::W)) {
			bat2.moveLeft();
		}
		if (Keyboard::isKeyPressed(Keyboard::S)) {
			bat2.moveRight();
		}
		else if (Keyboard::isKeyPressed(sf::Keyboard::Escape)){
			window.close();
		}
		/*
		Update the frame
		*********************************************************************
		*********************************************************************
		*********************************************************************
		*/


		// Handle ball hitting the bottom
		if (ball.getPosition().top > windowHeight){
			// reverse the ball direction
			ball.reboundSides();
		}

		// Handle ball hitting top
		if (ball.getPosition().top < 0)	{

			ball.reboundSides();
		}

		// Handle ball hitting sides

		if (ball.getPosition().left < 0 || ball.getPosition().left + 10 > windowWidth){
			
			ball.addPointA();
			ball.restartBall();
			ball.reboundBat();
			
		}
		if (ball.getPosition().left > windowWidth || ball.getPosition().left + 1004 < windowWidth){ //repair thus
			ball.addPointB();
			ball.restartBall();
			ball.reboundBat();
			

		}
		// Has the ball hit the bat?
		if (ball.getPosition().intersects(bat.getPosition())){
			// Hit detected so reverse the ball and score a point
			ball.reboundBat();
		}
		if (ball.getPosition().intersects(bat2.getPosition())){
			// Hit detected so reverse the ball and score a point
			ball.reboundBat();
		}
		ball.update();
		bat.update();
		bat2.update();
		// Update the HUD text
		std::stringstream ss;
		ss << "    Lives:" << ball.lives<<"       Lives:"<< ball.lives2;
		hud.setString(ss.str());
		/*
		Draw the frame
		*********************************************************************
		*********************************************************************
		*********************************************************************
		*/

		// Clear everything from the last frame
		window.clear(Color(26, 128, 182, 255));

		window.draw(bat.getShape());
		window.draw(bat2.getShape());

		window.draw(ball.getShape());

		// Draw our score
		window.draw(hud);

		// Show everything we just drew
		window.display();
	}// This is the end of the "while" loop
		
	return 0;
}
		
