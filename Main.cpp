/**
Main.cpp
Vector Graphics 

Author: Henry Bryant

CURRENT BUGS:

COMPLETED BUGS: 

*/
#include "Game.h"
#include <fstream>
#include <string.h>
#include <iostream>

int main()
{
    std::cout << "CONTROLS:\nPress SPACE to Restart Program.\nPress ESC to Save ScreenShot and Close Program.\n";
    std::cout << "------------------------------------------------------------------------------------------------------------------------\n";

    //init game engine
    Game game;
    //game loop

    while (game.isRunning())
    {
        //update 
        game.update();
        //render
        game.render();
        
    }
    //end of application
    return 0;
    
}