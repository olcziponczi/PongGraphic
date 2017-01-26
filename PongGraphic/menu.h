#pragma once
#include "stdafx.h"
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
	
	
	RectangleShape title;
	RectangleShape start;
	RectangleShape history;
	RectangleShape quit;
	
	Font font;
	void createMenu();
	void createGame();
	MenuPosition currentPosition = START;

	int hiPoints;
	




private:
	int i=0;

	const int windowHeight = 768;
	const int windowWidth = 1024;


	

	
	
};

