#include "stdafx.h"
#include "menu.h"
#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>



menu::menu() {

	while (!state == 3) {

		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			i++;
		}
		if (Keyboard::isKeyPressed(Keyboard::Return)) {

			i = (state);
			switch (i) {

			case 0:
				startMenu();
				//getch();
			case 1:
				startGame();
				//getch();
			case 2:
				gameOver();
				//getch();
			case 3:
				endGame();
				break;
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Down)) {

			i--;
		}
		if (Keyboard::isKeyPressed(Keyboard::Return)) {

			i = (state);
			switch (i) {

			case 0:
				startMenu();
				break;
			case 1:
				startGame();
				break;
			case 2:
				gameOver();
				break;
			case 3:
				endGame();
				break;
			}
		}
		state = END;
	}
}

void menu::createMenu() {



}

void menu::startMenu() {


}

void menu::startGame() {


}

void menu::gameOver(){


}

void menu::endGame() {


}