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
	Font font;
	Text text;
	
	void startMenu();
	void startGame();
	void gameOver();
	void endGame();
private:
	int i=0;
	
	
};

