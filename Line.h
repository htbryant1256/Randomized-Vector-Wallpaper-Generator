#ifndef LINE_H
#define LINE_H

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Network.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

class Line
{
public:
	Line();

	sf::Font font;
	sf::Text text;
	sf::RectangleShape displayRect;
	sf::RectangleShape vectorLine;
	sf::RectangleShape cursor;
	void updateLine();
	void initLine(int, int);

private:
	//char colliding(int,int);
	int xVel, yVel;
	int angle, maxVelocity;

	int windowWidth, windowHeight;

	bool collidesTop();
	bool collidesBottom();
	bool collidesLeft();
	bool collidesRight();
};
#endif