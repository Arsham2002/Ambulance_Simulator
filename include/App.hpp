#ifndef __APP_HPP
#define __APP_HPP
#include <iostream>
#include "level.hpp"
using namespace std;
class App
{
    public:
        int app();//RUN Program 
        void play(); // RUN play
    private:
        level* Lev; // information of current level
        
};


#endif //APP_HPP

