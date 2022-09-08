#include "line.h"
#include <stdlib.h>

//Private Functions---------------------------------------------------------------------------------
void Line::initLine(int windowWidth, int windowHeight)
{
    this->windowHeight = windowHeight;
    this->windowWidth = windowWidth;

    maxVelocity = 4;
    xVel = rand() % maxVelocity - maxVelocity;
    yVel = rand() % maxVelocity - maxVelocity;
    angle = 0;
    /*
    if (!font.loadFromFile("arial.ttf"))
    {
        std::cout << "Error Loading Font\n";
    }
    text.setFont(font);
    text.setFillColor(sf::Color::White);
    text.setOutlineColor(sf::Color::Black);
    text.setOutlineThickness(5);
    text.setPosition(sf::Vector2f(20, 14));
    text.setScale(sf::Vector2f(.8, .8));
    text.setString("X Velocity: " + std::to_string(xVel) +
                 "\nX Coordinate: " + std::to_string(cursor.getPosition().x));
    
    displayRect.setPosition(sf::Vector2f(10, 10));
    displayRect.setSize(sf::Vector2f(350, 100));
    displayRect.setFillColor(sf::Color::Black);
    displayRect.setOutlineColor(sf::Color::White);
    displayRect.setOutlineThickness(3);
    */
    vectorLine.setPosition(rand() % this->windowWidth + 1, rand() % this->windowHeight + 1);
    if (this->windowHeight >= this->windowWidth) {
        vectorLine.setSize(sf::Vector2f(1, this->windowHeight * 1.5));
    }
    else {
        vectorLine.setSize(sf::Vector2f(1, this->windowWidth * 1.5));
    }
    vectorLine.setFillColor(sf::Color(255, 117, 24));
    //vectorLine.setFillColor(sf::Color::White);
    //vectorLine.setFillColor(sf::Color(33, 173, 168));

    /**
    cursor.setPosition(vectorLine.getPosition());
    cursor.setSize(sf::Vector2f(3, 3));
    cursor.setOutlineColor(sf::Color::Black);
    cursor.setOutlineThickness(1);
    */
}

bool Line::collidesTop() {
    return vectorLine.getPosition().y <= 0;
}

bool Line::collidesBottom() {
    return vectorLine.getPosition().y >= windowHeight;
}

bool Line::collidesLeft() {
    return vectorLine.getPosition().x <= 0;
}

bool Line::collidesRight() {
    return vectorLine.getPosition().x >= windowWidth;
}

//Public Functions---------------------------------------------------------------------------------

void Line::updateLine()
{
    if (collidesLeft())
    {
        xVel = rand() % maxVelocity + 1;

        //  vectorLine.setFillColor(sf::Color::Cyan);
    }
    else if (collidesRight())
    {
        xVel = rand() % (maxVelocity - 1) - maxVelocity;
        //  vectorLine.setFillColor(sf::Color::Green);
    }
    else if (collidesTop())
    {
        yVel = rand() % maxVelocity + 1;
        //  vectorLine.setFillColor(sf::Color(255, 117, 24));
    }
    else if (collidesBottom())
    {
        yVel = rand() % (maxVelocity - 1) - maxVelocity;
        //  vectorLine.setFillColor(sf::Color::Magenta);
    }

    vectorLine.move(sf::Vector2f(xVel, yVel));

    /*
    text.setString("X Velocity: " + std::to_string(xVel) +
                 "\nY Veclocity: " + std::to_string(yVel) +
                 "\nCoordinates: ( " + std::to_string(int(cursor.getPosition().x)) + " , " + std::to_string(int(cursor.getPosition().y)) + " )");

    cursor.setPosition(sf::Vector2f(vectorLine.getPosition().x - (cursor.getSize().x / 2), vectorLine.getPosition().y - (cursor.getSize().y / 2)));
    */
    vectorLine.setFillColor(sf::Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1));

    vectorLine.rotate(2);
}
//Constructors-------------------------------------------------------------------------------------

Line::Line() {
    srand(time(NULL));
 
   // initLine();
}