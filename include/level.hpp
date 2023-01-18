#ifndef __LEVEL_HPP
#define __LEVEL_HPP
using namespace std;
#include "Ambulance.hpp"
#include "Walls.hpp"
#include "player.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
class level
{
    public:
        level();//set level 1
        ~level();//free dynamic memory
        void draw(sf::RenderWindow&);//print board of game
        void move(char);//calling moving of car
        bool check();//Checking if the game is over?
        bool win;//Is the player win?
        void next_level();//set next level(level 2 or 3)
        int ret_nwall()const;//return number of walls in current level 
        int cal_score();//calculate score until now
        player you;//information of player
    private:
        int nWall;//number of walls in this level
        int nowlev;//level number
        int hospital;//coordinate of hospital(Its x is always the last number)
        rectangle table;//Size of row and column
        Ambulance* car;//information of car
        Walls* wall;//information of walls
        int nmove;//the number of moves made by the user
};

#endif // LEVEL_HPP
