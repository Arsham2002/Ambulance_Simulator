#ifndef AMBULANCE_HPP
#define AMBULANCE_HPP
#include <iostream>
#include "Walls.hpp"
using namespace std;
enum color{WHITE,RED,GREEN, CYAN};
struct rectangle
{
    int row;
    int col;
};
class Ambulance
{
    public:
        explicit Ambulance();//constructor 
        void moving(char, rectangle&, Walls*, int, int, int);//change coordinate
        coordinate pos;// coordinate
        color where;
        //status--RED:GAME OVER or LOSE 1Heart--GREEN:Arrive to Hospital  
        int Health;//Hearts of car MAX:3
        
};

#endif // AMBULANCE_HPP
