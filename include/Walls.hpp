#ifndef WALL_HPP
#define WALL_HPP
struct coordinate
{
    int x;
    int y;
};
class Walls
{
    public:
        coordinate pwall;// coordinate of walls(y in this coordinate is hole of wall)
};

#endif // WALL_HPP
