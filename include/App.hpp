#ifndef __APP_HPP
#define __APP_HPP
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "level.hpp"
using namespace std;
class App
{
    public:
        App();
        int app();//RUN Program 
        void play(); // RUN play
    private:
        level* Lev; // information of current level
        sf::RenderWindow window;
        
};


#endif //APP_HPP

