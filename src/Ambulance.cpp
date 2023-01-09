#include "Ambulance.hpp"
#include <stdexcept>
#include <ctime>
using namespace std;
Ambulance::Ambulance()
{
    pos.y = 1;
    pos.x = 0;
    where = WHITE;
    Health = 3;
}
void Ambulance::moving(char ch, rectangle& limit, Walls* wall, int nwall, int hosy, int hosx)
//change coordinate of car and set status 
{
    bool flag = true;//be false if the car leaves the ground
    switch(ch)
    {
        case 'w':
        if(pos.y-1 < 0)
        {
            where = RED;
            Health--; 
            flag = false;
            break;
        }
        pos.y--;
        break;
        case 's':
        if(pos.y+1 >= limit.row)
        {
            where = RED;
            Health--; 
            flag = false;
            break;
        }
        pos.y++;
        break;
        case 'd':
        break;
        case '0':
        cout << endl;
        exit(0);
        break;
        default:
        throw invalid_argument("\nenter correctly: ");
    }
    pos.x++;
    for(size_t i = 0; i < nwall; i++)
        if(wall[i].pwall.x == pos.x && wall[i].pwall.y != pos.y)
        {
            //impact to a wall
            where = RED;
            Health--;
            return;
        }
    else if(pos.y == hosy && pos.x == hosx-1)//arrive to hospital
            where = GREEN;
    else if(flag)//not special staus
        where = WHITE;
}

