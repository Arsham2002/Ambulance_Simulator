#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <string>
using namespace std;
class player
{
    public:
        player();//set score of player 0
        void set_info();//take information of player 
        void set_sc(int x);//change score
        int get_sc();//return score
        void record();//append in files
    private:
        string name;
        int score;
};

#endif // PLAYER_HPP
