#include "Game.h"
#include <iostream>

//Private Functions---------------------------------------------------------------------------------
void Game::initVariables()
{
	window = nullptr;
    promptUserAndInitResolution();
    promptUserAndInitTimer();
    videoMode.width = windowWidth;
    videoMode.height = windowHeight;
}

void Game::initWindow()
{
    window = new sf::RenderWindow(videoMode, "Vector Wallpaper Maker", sf::Style::Titlebar | sf::Style::Close);
    //window->setVerticalSyncEnabled(true);
    window->setFramerateLimit(120);
}

//Event Polling------------------------------------------------------------------------------------
//Handles closing the window with the ESC key, and with the window 'X' button.
void Game::pollEvents()
{    
    while (window->pollEvent(ev))
    {
        switch (ev.type)
        {
        case sf::Event::Closed:
            window->close();
            break;
        case sf::Event::KeyPressed:
            if (ev.key.code == sf::Keyboard::Escape)
            {
                sf::Texture texture;
                texture.create(windowWidth, windowHeight);
                texture.update(*window);
                texture.copyToImage().saveToFile("ScreenCap/screenshot.png");
                std::cout << "\nScreenshot saved to " << "ScreenCap/screenshot.png" << std::endl;
                
                window->close();
                break;
            }
        }
    }
}

void Game::promptUserAndInitTimer()
{
    std::cout << "Enter Desired Run Time in Seconds:";
    std::cin >> timerInput;
    timer = timerInput * 120;
}

void Game::promptUserAndInitResolution() {
    std::cout << "Enter Desired X Resolution:";
    std::cin >> windowWidth;
    std::cout << "Enter Desired Y Resolution:";
    std::cin >> windowHeight;
}

//Public Functions---------------------------------------------------------------------------------
void Game::update()
{
    pollEvents();

    if (timer >= 0) {
        line.updateLine();
        timer--;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        window->clear(sf::Color::Black);
        timer = timerInput * 120;
    }
}

void Game::render()
{
    if (timer >= 0) {
        // window->draw(line.cursor);
        window->draw(line.vectorLine);
        //  window->draw(line.displayRect);
        //  window->draw(line.text);
        window->display();
    }
}

bool Game::isRunning()
{
    return window->isOpen();
}

//constructors ------------------------------------------------------------------------------------
Game::Game()
{
	initVariables();
	initWindow();
    line.initLine(windowWidth, windowHeight);
}