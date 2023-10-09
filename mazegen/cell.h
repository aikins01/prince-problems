#ifndef CELL_H
#define CELL_H

class Cell
{
public:
    int x, y;
    bool visited;
    bool pathVisited;
    bool walls[4];

    Cell(int x = 0, int y = 0) : x(x), y(y), visited(false), pathVisited(false), walls{true, true, true, true} {}
};

#endif