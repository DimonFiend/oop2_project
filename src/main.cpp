#include "GameEngine.h"
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    try
    {
        GameEngine game;
        game.run();
    }
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
   
    return 0;
}
