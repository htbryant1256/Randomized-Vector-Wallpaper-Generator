/*
Game.h
Game header file
Psudo game engine class
*/
#ifndef GAME_H
#define GAME_H
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Network.hpp"
#include "Line.h"
#include <iostream>

class Game
{
private:
	//objects
	sf::RenderWindow* window;
	sf::Event ev;
	sf::VideoMode videoMode;

	//objects from header files
	Line line;

	//private Variables
	int windowHeight;
	int windowWidth;
	int timer, timerInput;

	//functions
	void initVariables();
	void initWindow();
	void pollEvents();
	void promptUserAndInitResolution();
	void promptUserAndInitTimer();

public:
	//constructors
	Game();

	//functions
	bool isRunning();
	void update();
	void render();

};

#endif