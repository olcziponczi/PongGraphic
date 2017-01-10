#pragma once
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <string>


using namespace std;
using namespace sf;

class menu
{
public:
	menu();
	enum gameState {MENU,GAME,GAME_OVER,END};
	gameState state;	
	RectangleShape start;
	RectangleShape history;
	RectangleShape quit;
	Font font;
	Text text;
	void menuLogic();
	void startMenu();
	void startGame();
	void gameOver();
	void gameHistory();
	void endGame();
	void createMenu();
private:
	int i=0;
	
	
};

