
#include "App.hpp"
#define window_x 310
#define window_y 250
using namespace std;
void print_color(string s, color txtcolor);
App::App():window(sf::VideoMode(window_x, window_y), "Ambulance Simulator", sf::Style::Resize | sf::Style::Close)
{}
int App::app()
{
    sf::Texture background;
    sf::Texture icon_start;
    sf::Texture icon_exit;

    if(!background.loadFromFile("../assest/background.png"))
        cerr << "Can't open background!";
    if(!icon_start.loadFromFile("../assest/start3.png"))
        cerr << "Can't open start!";
    if(!icon_exit.loadFromFile("../assest/exit3.png"))
        cerr << "Can't open exit!";

    sf::Sprite back_sp;
    sf::Sprite start_sp;
    sf::Sprite exit_sp;

    back_sp.setTexture(background);
    start_sp.setTexture(icon_start);
    exit_sp.setTexture(icon_exit);

    start_sp.setPosition(window_x - 175, window_y - 200);
    exit_sp.setPosition(window_x - 175,window_y - 150);



    while(window.isOpen())
    {
        sf::Event event;
        while((window.pollEvent(event)))
        {
            switch(event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;  
                case sf::Event::MouseButtonPressed:
                    if(start_sp.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
                    {
                        Lev = new level;
                        play();
                        delete Lev;
                    }
                    if(exit_sp.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
                        window.close();
                    break;
            }
        }
        window.clear();
        window.draw(back_sp);
        window.draw(start_sp);
        window.draw(exit_sp);
        window.display();
    }
    return 0;
}
void App::play()
{
    Lev->you.set_info(window);
    while(window.isOpen())
    {
        sf::Event event;
        window.clear();
        Lev->draw(window);
        window.display();
        while((window.pollEvent(event)))
        {
            switch(event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }
    }
    // string n = "Your Score is: " + to_string(Lev->cal_score()) + '\n';
    // Lev->you.record();
    // if(Lev->win)
    // {
    //     if(Lev->ret_nwall() <= 3)
    //     {
    //         print_color((string)("\nYOU WIN\n")+n, color::GREEN);
    //         cout << "Next level? y/n: ";
    //         while(1)
    //         {
    //             system("stty raw");
    //             cin >> pmove;
    //             system("stty cooked");
    //             pmove = tolower(pmove);
    //             if(pmove == '0')
    //             {
    //                 cout << endl;
    //                 exit(0);
    //             }
    //             else if(pmove != 'y' && pmove != 'n')
    //                 cout << "\nWHAT?! : ";
    //             else
    //                 break;
    //         }
    //         if(pmove == 'y')
    //         {
    //             Lev->next_level();
    //             play();
    //         }
    //         cout << endl;
    //     }
    //     else//if the player finishes the game
    //     {
    //         print_color((string)("\n\t      Well Done \n    ***You passed all the steps***\n\t  ")+n, color::CYAN);
    //     }
    // }
    // else
    //     print_color((string)("\nYOU LOSE\n")+n, color::RED);
}