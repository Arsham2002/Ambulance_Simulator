#include "player.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
#define len_name 12
#define window_x 310
#define window_y 250
player::player():score(0),name("")
{}
void player::set_info(sf::RenderWindow& window)
{
    sf::Texture background;
    if(!background.loadFromFile("../assest/background.png"))
        cerr << "Can't open background!";
    sf::Sprite back_sp;
    back_sp.setTexture(background);

    sf::RectangleShape rectangle(sf::Vector2f(125, 25));
    rectangle.setFillColor(sf::Color::Blue);
    rectangle.setPosition(window_x - 280, window_y - 200);

    sf::Text text;
    text.setString("Enter Your name");
    sf::Font font;
    if (!font.loadFromFile("../assest/oxygen/Oxygen-Regular.ttf"))
        cerr << "Can't open font!";
    
    text.setFont(font);
    text.setCharacterSize(15);
    text.setPosition(window_x - 275, window_y - 195);
    bool Nend = true;
    while(window.isOpen() && Nend)
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::TextEntered:
                    name += event.TextEntered;
                    text.setString(name);
                    break;
                default:
                    if(event.key.code == sf::Keyboard::Enter)
                        Nend = false; 
                    break;
            }
        }
        window.clear();
        window.draw(back_sp);
        window.draw(rectangle);
        window.draw(text);
        window.display();
    }
    ifstream file("../PLAYER.txt", ios::ate);
    if(!file.is_open())
    {
        file.close();
        ifstream file("../PLAYER.txt", ios::out | ios::in);
    }
    file.close();//just create text file if doesn't exist
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

