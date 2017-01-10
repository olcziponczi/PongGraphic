#include "stdafx.h"
#include "bat.h"
#include "bat2.h"
#include "ball.h"
#include "menu.h"
#include <sstream>
#include <cstdlib>
#include <conio.h>

#include <SFML/Graphics.hpp>
using namespace sf;


void createMenu();
void createGame();



int main() {
	
	createMenu();
		
	return 0;
}

enum MenuPosition { START, HISTORY, QUIT };

MenuPosition currentPosition = START;
const int windowWidth = 1024;


MenuPosition& operator++(MenuPosition& pos) {
	if (pos < 2)
	pos = static_cast<MenuPosition>(pos + 1);

	return pos;
}


MenuPosition& operator--(MenuPosition& pos) {
	if (pos >0)
	pos = static_cast<MenuPosition>(pos - 1);
	return pos;
}


void createMenu() {

	

	const int windowHeight = 768;

	RenderWindow window(VideoMode(windowWidth, windowHeight), "Pong");
	Event event;
	while (true)
	{

	
		while (window.pollEvent(event)) {

			if (event.type == Event::Closed)	//spr. czy ktoœ nie zamkn¹³ okna
				window.close();

			Font font;
			font.loadFromFile("font.ttf");
			Text play, history, quit;

			play.setFont(font);
			history.setFont(font);
			quit.setFont(font);
			//	rectangle.setPosition(rectangleCoord);
			stringstream draw;
			//	rectangle.setPosition(rectangleCoord);
			play.setCharacterSize(75);
			history.setCharacterSize(75);
			quit.setCharacterSize(75);
			//	rectangle.setOutlineThickness(5);
			//	rectangle.setOutlineColor(Color::Green);
			//	rectangle.setFillColor(Color::Transparent);
			play.setFillColor(sf::Color::White);
			history.setFillColor(sf::Color::White);
			quit.setFillColor(sf::Color::White);

			std::stringstream ss;
			std::stringstream ss1;
			std::stringstream ss2;

			ss << "START";
			ss1 << "HISTORIA";
			ss2 << "WYJSCIE";

			int coordStartY = 150;

			Vector2f coordStart = Vector2f(windowWidth - 550, coordStartY);
			Vector2f coordHistory = Vector2f(windowWidth - 550, coordStartY + 150);
			Vector2f coordQuit = Vector2f(windowWidth - 550, coordStartY + 300);

			play.setPosition(coordStart);
			play.setString(ss.str());

			history.setPosition(coordHistory);
			history.setString(ss1.str());

			quit.setPosition(coordQuit);
			quit.setString(ss2.str());

			window.clear(Color(26, 128, 182, 255));
			switch (currentPosition)
			{
			case START:
				play.setOutlineThickness(20);
				play.setOutlineColor(Color::Magenta);
				if (event.type == Event::KeyReleased && event.key.code == Keyboard::Return) {

					createGame();
				}
				break;
			case HISTORY:
				history.setOutlineThickness(20);
				history.setOutlineColor(Color::Magenta);
				break;
			case QUIT:
				quit.setOutlineThickness(20);
				quit.setOutlineColor(Color::Magenta);
				break;
			}

			window.draw(play);
			window.draw(history);
			window.draw(quit);



			if (event.type == Event::KeyReleased && event.key.code == Keyboard::Down) {

				++currentPosition;

			}
			if (event.type == Event::KeyReleased  && event.key.code == Keyboard::Up) {

				--currentPosition;
			}

			//	window.draw(rectangle);

			window.display();
		}
	}
}



void createGame() {


	const int windowWidth = 1024;
	const int windowHeight = 768;

	RenderWindow window(VideoMode(windowWidth, windowHeight), "Pong");

	Bat bat(windowWidth - 20, windowHeight / 2);
	Bat2 bat2(windowWidth - 1004, windowHeight / 2);

	Ball ball(windowWidth / 2, 1);

	Text hud, hud1;


	Font font;
	font.loadFromFile("font.ttf");

	hud.setFont(font);

	hud.setCharacterSize(75);

	hud.setFillColor(sf::Color::White);

	hud1.setFont(font);

	hud1.setCharacterSize(75);

	hud1.setFillColor(sf::Color::White);

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)	//spr. czy ktoœ nie zamkn¹³ okna
				window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			bat.moveLeft();
		}
		if (Keyboard::isKeyPressed(Keyboard::Down)) {

			bat.moveRight();
		}
		if (Keyboard::isKeyPressed(Keyboard::W)) {
			bat2.moveLeft();
		}
		if (Keyboard::isKeyPressed(Keyboard::S)) {
			bat2.moveRight();
		}
		else if (Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			window.close();
		}
		/*
		Update the frame
		*********************************************************************
		*********************************************************************
		*********************************************************************
		*/


		// Handle ball hitting the bottom
		if (ball.getPosition().top > windowHeight) {
			// reverse the ball direction
			ball.reboundSides();
		}

		// Handle ball hitting top
		if (ball.getPosition().top < 0) {

			ball.reboundSides();
		}

		// Handle ball hitting sides

		if (ball.getPosition().left < 0 || ball.getPosition().left + 10 > windowWidth) {

			ball.addPointA();
			ball.restartBall();
			ball.reboundBat();

		}
		if (ball.getPosition().left > windowWidth || ball.getPosition().left + 1004 < windowWidth) { //repair thus
			ball.addPointB();
			ball.restartBall();
			ball.reboundBat();


		}
		// Has the ball hit the bat?
		if (ball.getPosition().intersects(bat.getPosition())) {
			// Hit detected so reverse the ball and score a point
			ball.reboundBat();
		}
		if (ball.getPosition().intersects(bat2.getPosition())) {
			// Hit detected so reverse the ball and score a point
			ball.reboundBat();
		}
		ball.update();
		bat.update();
		bat2.update();
		// Update the HUD text
		std::stringstream ss;
		std::stringstream ss1;
		ss << "Lives: " << ball.lives;
		ss1 << "Lives: " << ball.lives2;
		Vector2f coord = Vector2f(windowWidth - 1000, 10);
		Vector2f coord2 = Vector2f(windowWidth - 150, 10);

		hud.setPosition(coord);
		hud.setString(ss.str());
		hud1.setPosition(coord2);
		hud1.setString(ss1.str());



		window.clear(Color(26, 128, 182, 255));

		window.draw(bat.getShape());
		window.draw(bat2.getShape());

		window.draw(ball.getShape());

		window.draw(hud);
		window.draw(hud1);
		// Show everything we just drew
		window.display();
	}// This is the end of the "while" loop
}
