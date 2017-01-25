#include "stdafx.h"
#include "bat.h"
#include "bat2.h"
#include "ball.h"
#include "menu.h"
#include <sstream>
#include <cstdlib>
#include <conio.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;


	
	MenuPosition& operator++(MenuPosition& pos) {
		if (pos < 2)
			pos = static_cast<MenuPosition>(pos + 1);
			return pos;
	}


	MenuPosition& operator--(MenuPosition& pos) {
		if (pos > 0)
			pos = static_cast<MenuPosition>(pos - 1);
		return pos;
	}

	menu::menu() {
}


void menu::createMenu() {

	/*sf::SoundBuffer buffer;
	buffer.loadFromFile("pong2.wav");
	sf::Sound sound;
	sound.setBuffer(buffer);
	sound.play();
	*/
	RenderWindow window(VideoMode(windowWidth, windowHeight), "Pong");
	Event event;
	while (true)
	{


		while (window.pollEvent(event)) {

			if (event.type == Event::Closed)	//spr. czy ktoœ nie zamkn¹³ okna
				window.close();

			Font font;
			font.loadFromFile("font.ttf");
			Text play, history, quit, title;

			title.setFont(font);
			play.setFont(font);
			history.setFont(font);
			quit.setFont(font);
	
			stringstream draw;
			
			title.setCharacterSize(180);
			play.setCharacterSize(150);
			history.setCharacterSize(150);
			quit.setCharacterSize(150);
	
			title.setFillColor(sf::Color::White);
			play.setFillColor(sf::Color::White);
			history.setFillColor(sf::Color::White);
			quit.setFillColor(sf::Color::White);


			std::stringstream ss;
			//std::stringstream ss1;
			std::stringstream ss2;
			std::stringstream ss3;

			ss3 << "PONG v2";
			ss << "START";
			//ss1 << "HISTORY";
			ss2 << "EXIT";

			int coordStartY = 150;

			Vector2f coordTitle = Vector2f(windowWidth - 600, coordStartY-150);
			Vector2f coordStart = Vector2f(windowWidth - 600, coordStartY);
			//Vector2f coordHistory = Vector2f(windowWidth - 600, coordStartY + 100);
			Vector2f coordQuit = Vector2f(windowWidth - 600, coordStartY + 100);


			title.setPosition(coordTitle);
			title.setString(ss3.str());

			play.setPosition(coordStart);
			play.setString(ss.str());

			//history.setPosition(coordHistory);
			//history.setString(ss1.str());

			quit.setPosition(coordQuit);
			quit.setString(ss2.str());

			window.clear(Color(0, 0, 0, 0));

			switch (currentPosition)
			{
			case START:
				play.setOutlineThickness(10);
				play.setOutlineColor(Color::Magenta);
				if (event.type == Event::KeyReleased && event.key.code == Keyboard::Return) {

					createGame();
				}
				break;
			/*case HISTORY:
				history.setOutlineThickness(10);
				history.setOutlineColor(Color::Magenta);
				if (event.type == Event::KeyReleased && event.key.code == Keyboard::Return) {

					showHistory();
				}

				
				break;
				*/
			case QUIT:
				quit.setOutlineThickness(10);
				quit.setOutlineColor(Color::Magenta);

				if (event.type == Event::KeyReleased && event.key.code == Keyboard::Return) {
					window.close();
			

				}
				break;
			}
			

			if (event.type == Event::KeyReleased && event.key.code == Keyboard::Down) {

				++currentPosition;

			}
			if (event.type == Event::KeyReleased  && event.key.code == Keyboard::Up) {

				--currentPosition;
			}

			window.draw(title);
			window.draw(play);
			//window.draw(history);
			window.draw(quit);
			window.display();
		}
	}
}



void menu::createGame() {


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
	

		if (ball.getPosition().top > windowHeight) {
	
			ball.reboundSides();
		}


		if (ball.getPosition().top < 0) {

			ball.reboundSides();
		}

	

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
		if (ball.getPosition().intersects(bat.getPosition())) {
			ball.reboundBat();
		}
		if (ball.getPosition().intersects(bat2.getPosition())) {
			ball.reboundBat();
		}
		ball.update();
		bat.update();
		bat2.update();

		std::stringstream ss;
		std::stringstream ss1;
		ss << "Points: " << ball.lives;
		ss1 << "Points: " << ball.lives2;
		Vector2f coord = Vector2f(windowWidth - 1000, 10);
		Vector2f coord2 = Vector2f(windowWidth - 150, 10);


		if (ball.lives == 10 || ball.lives2 == 10) {
			endGame();
		}

		hud.setPosition(coord);
		hud.setString(ss.str());
		hud1.setPosition(coord2);
		hud1.setString(ss1.str());



		window.clear(Color(0, 0, 0, 0));


		window.draw(bat.getShape());
		window.draw(bat2.getShape());

		window.draw(ball.getShape());

		window.draw(hud);
		window.draw(hud1);
		window.display();
	}}


void menu::endGame() {

	Vector2f coordText = Vector2f(windowWidth - 1000, 10);
	std::stringstream p;
	points.setPosition(coordText);
	points.setString(p.str());
	if(ball.lives>ball.lives2){
	p <<"AND THE WINNER IS..." 
		}
	window.draw(points);

}
/*void menu::createHistory() {

	std::fstream plik;
	plik.open("hiscore.txt", std::ios::in | std::ios::out);
	if (plik.good() == true)
	{
		//tu operacje na pliku (zapis/odczyt)
		plik << hiPoints;
		plik.close();
	}

}
*/
/*void menu::showHistory() {
	int coordStartY = 150;
	RenderWindow window(VideoMode(windowWidth, windowHeight), "Pong");

	Font font;
	font.loadFromFile("font.ttf");
	Text points;

	points.setFont(font);
	points.setCharacterSize(180);
	points.setFillColor(sf::Color::White);
	Vector2f coordPoints = Vector2f(windowWidth - 600, coordStartY);
	points.setPosition(coordPoints);
	std::stringstream p;

	p << hiPoints;
		
	points.setString(p.str());

	window.draw(points);
	stringstream draw;

	}
	*/