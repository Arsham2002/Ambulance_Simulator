#include "player.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
#define len_name 12
player::player():score(0)
{}
void player::set_info()
{
    system("clear");
    ifstream file("../PLAYER.txt", ios::ate);
    if(!file.is_open())
    {
        file.close();
        ifstream file("../PLAYER.txt", ios::out | ios::in);
    }
    file.close();//just create text file if doesn't exist
    cout << "Enter your username(maximum "<< len_name << " char): ";
    cin >> name;
}
void player::record()
{
    {
        ofstream file("../PLAYER.txt", ios::app);
        file <<setw(len_name) << left << name << ":" << score << endl;
        file.close();
    }
}
int player::get_sc()
{
    return score;
}
void player::set_sc(int x)
{
    score = x;
} 

