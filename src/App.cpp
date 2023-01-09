
#include "App.hpp"
using namespace std;
void print_color(string s, color txtcolor);
int App::app()
{
    char command;
    system("clear");
    cout << "Welcome to Ambulance simulator game\n";
    do
    {
        cout << "0:Exit \n1:Play \nEnter---> ";
        cin >> command;
        cin.ignore();
        switch(command)
        {
            case '0':
            cout << "Thank you for playing...BYE!\n";
            break;
            case '1':
            Lev = new level;
            play();
            delete Lev;
            break;
            default:
            cout << "What do you mean from " << command << "; Please Enter again\n"; 
            break;
        }
    }while(command != '0');
    return 0;
}
void App::play()
{
    system("clear");
    char pmove;
    while(1)
    {
        Lev->draw();
        if(Lev->check())
            break;
        cout <<"\nEnter w or s or d: ";
        while(1)
        {
            system("stty raw"); //get charecter without Enter '\n'
            cin >> pmove;
            system("stty cooked");
            try
            {
                Lev->move(pmove);
                break;
            }
            catch(invalid_argument& e)
            {
                cout << e.what();
            }
        }
    }
    string n = "Your Score is: " + to_string(Lev->cal_score()) + '\n';
    Lev->you.record();
    if(Lev->win)
    {
        if(Lev->ret_nwall() <= 3)
        {
            print_color((string)("\nYOU WIN\n")+n, color::GREEN);
            cout << "Next level? y/n: ";
            while(1)
            {
                system("stty raw");
                cin >> pmove;
                system("stty cooked");
                pmove = tolower(pmove);
                if(pmove == '0')
                {
                    cout << endl;
                    exit(0);
                }
                else if(pmove != 'y' && pmove != 'n')
                    cout << "\nWHAT?! : ";
                else
                    break;
            }
            if(pmove == 'y')
            {
                Lev->next_level();
                play();
            }
            cout << endl;
        }
        else//if the player finishes the game
        {
            print_color((string)("\n\t      Well Done \n    ***You passed all the steps***\n\t  ")+n, color::CYAN);
        }
    }
    else
        print_color((string)("\nYOU LOSE\n")+n, color::RED);
}