#include "level.hpp"
#include <iostream>
#define window_x 310
#define window_y 250
using namespace std;
void print_color(string s, color txtcolor)
{
    //print text of "s" with "txtcolor" color
    switch(txtcolor)
    {
        case RED:
        std::cout << "\033[0;31m";
        break;  
        case GREEN:
        std::cout << "\033[0;32m";
        break;
        case CYAN:
        std::cout << "\033[1;36m";
        break;
        default:
        break;
    }
    std::cout << s << "\033[0m";
}
level::level():win(false), nowlev(1), nmove(0),nWall(2)
{
    table.row = 315;
    table.col = 244;
    car = new Ambulance;
    wall = new Walls[2];
    wall[0].pwall.x = 2*50;
    wall[0].pwall.y = 2*20;
    wall[1].pwall.x = 4*50;
    wall[1].pwall.y = 5*40;
    hospital = 2*50;
}
void level::draw(sf::RenderWindow& window)
{
    int th = 0;
    sf::Texture road;
    if(!road.loadFromFile("../assest/road3.png"))
        cerr << "Can't open road!";
    sf::Sprite road_sp;
    road_sp.setTexture(road);
    window.draw(road_sp);

    sf::Texture wall_t;
    if(!wall_t.loadFromFile("../assest/wall.png"))
        cerr << "Can't open wall!";
    sf::Sprite wall_sp;
    wall_sp.setTexture(wall_t);
    for(size_t i = 0; i < nWall; i++)
    {
        wall_sp.setPosition(wall[i].pwall.x,wall->pwall.y);
        window.draw(wall_sp);
    }

    sf::Texture car_t;
    if(!car_t.loadFromFile("../assest/car4.png"))
        cerr << "Can't open car!";
    sf::Sprite car_sp;
    car_sp.setTexture(car_t);
    wall_sp.setPosition(car->pos.x,car->pos.y);
    window.draw(car_sp);

    sf::Texture heart;
    if(!heart.loadFromFile("../assest/heart3.png"))
        cerr << "Can't open heart!";
    sf::Sprite heart_sp;
    heart_sp.setTexture(heart);
    for(size_t i = 0; i< car->Health; i++)
    {
        heart_sp.setPosition(window_x - 278 + i * 8,window_y - 10);
        window.draw(heart_sp);
    }
}
void level::move(char ch)
{
    nmove++;
    car->moving(ch, table, wall, nWall, hospital, table.col);
    if(car -> where == GREEN)
        win = true;
}
bool level::check()
{
    
    if(car->Health == 0)
        return true;
    if(car->pos.x == table.col - 1)
    {
        if(hospital == car->pos.y)
            win = true;
        return true;
    }
    return false;
}
void level::next_level()
{
    nowlev++;
    car->pos.x = 0;
    car->pos.y = 2;
    car -> where = WHITE;
    win = false;
    table.row++;//each update level rows increase 1
    table.col += 2;//each update level columns increase 2
    nWall++;
    delete [] wall;
    wall = new Walls[nWall];
    if(nWall == 3)//goes level 2
    {
        wall[0].pwall.x = 2;
        wall[0].pwall.y = 0;
        wall[1].pwall.x = 5;
        wall[1].pwall.y = 3;
        wall[2].pwall.x = 7;
        wall[2].pwall.y = 1;
    }
    else//goes level 3
    {
        wall[0].pwall.x = 3;
        wall[0].pwall.y = 3;
        wall[1].pwall.x = 5;
        wall[1].pwall.y = 2;
        wall[2].pwall.x = 8;
        wall[2].pwall.y = 5;
        wall[3].pwall.x = 10;   
        wall[3].pwall.y = 3;
    }
}
int level::cal_score()
{
    you.set_sc(car->Health * 250 + (win? nowlev*1000: 0) - nmove*10);
    /*
    score calculate according to: each heart 250 point
    pass each level 1000 point
    any moving -10 ponit(if a player move useless his score decreases)
    */
    return you.get_sc();
}
int level::ret_nwall()const
{
    return nWall;
}
level::~level()
{
    delete [] wall;
    delete car;
}