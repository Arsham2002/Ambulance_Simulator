#include "level.hpp"
#include <iostream>
using namespace std;
void print_color(string s, color txtcolor)
{
    //print text of "s" with "txtcolor" color
    switch(txtcolor)
    {
        case RED:
        cout << "\033[0;31m";
        break;  
        case GREEN:
        cout << "\033[0;32m";
        break;
        case CYAN:
        cout << "\033[1;36m";
        break;
        default:
        break;
    }
    cout << s << "\033[0m";
}
level::level():win(false), nowlev(1), nmove(0),nWall(2)
{
    you.set_info();
    table.row = 4;
    table.col = 8;
    car = new Ambulance;
    wall = new Walls[2];
    wall[0].pwall.x = 2;
    wall[0].pwall.y = 0;
    wall[1].pwall.x = 6;
    wall[1].pwall.y = 3;
    hospital = 2;
}
void level::draw()
{
    system("clear");
    int th = 0;
    string line;
    for(size_t i = 0; i < table.col * 3 + 2; i++)
    {
        cout << '-';
        line += '-';
    }
    line += '\n';
    cout << '\n';
    for(size_t i = 0; i < table.row; i++)
    {
        bool flag;
        for(size_t j = 0 ; j < table.col; j++)
        {
            flag = true;//be false when car or wall be in this coordinate(i,j)
            if(j == 0)
                cout << "|";
            if(car->pos.x == j && car->pos.y == i)
            {
                print_color(" > ", car->where);
                flag = false;
            }
            if(th < nWall && wall[th].pwall.x == j)
            {
                if(flag)//if car is here doesn't print wall
                    cout << ( wall[th].pwall.y == i ? "   " : "[ ]" );
                th++;
                flag = false;
            }
            if(flag)//nothing is here
                cout << "   ";
            if(j == table.col-1)
            {
                cout << "|";
                if(i == hospital)
                    cout << "|H|";
            }
            
        }
        cout << endl; 
        th = 0;
    }
    cout << line;
    for(size_t i = 0 ; i < car -> Health; i++)//print heart of car
        print_color(" <3 ", RED);
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