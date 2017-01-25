#pragma once
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <string>
#include <fstream>


using namespace std;
using namespace sf;

enum MenuPosition { START, HISTORY, QUIT };

class menu
{
public:
	menu();
	
	RectangleShape title;
	RectangleShape start;
	RectangleShape history;
	RectangleShape quit;
	Font font;
	Text text;
	Text points;

	void createMenu();
	void createGame();
	MenuPosition currentPosition = START;

	int hiPoints;
	void endGame();


private:
	int i=0;
	const int windowHeight = 768;
	const int windowWidth = 1024;
	

	
	
};

