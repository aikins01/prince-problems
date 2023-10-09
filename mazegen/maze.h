#ifndef MAZE_H
#define MAZE_H

#include "cell.h"

class Maze
{
public:
    int rows, cols;
    std::vector<std::vector<Cell>> cells;
    std::vector<std::vector<bool>> path;

    Maze(int rows, int cols) : rows(rows), cols(cols), cells(rows, std::vector<Cell>(cols, Cell(0, 0))), path(rows, std::vector<bool>(cols, false))
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cells[i][j] = Cell(i, j);
            }
        }
    }

    void generateMaze()
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 3);

        std::stack<Cell *> stack;
        Cell *current = &cells[0][0];
        current->visited = true;
        stack.push(current);

        while (!stack.empty())
        {
            Cell *next = getNextCell(current, dis(gen));
            if (next)
            {
                removeWall(current, next);
                stack.push(next);
                next->visited = true;
                current = next;
            }
            else
            {
                current = stack.top();
                stack.pop();
            }
        }
    }

    Cell *getNextCell(Cell *cell, int direction)
    {
        int x = cell->x;
        int y = cell->y;
        switch (direction)
        {
        case 0: // top
            if (x > 0 && !cells[x - 1][y].visited)
                return &cells[x - 1][y];
            break;
        case 1: // right
            if (y < cols - 1 && !cells[x][y + 1].visited)
                return &cells[x][y + 1];
            break;
        case 2: // bottom
            if (x < rows - 1 && !cells[x + 1][y].visited)
                return &cells[x + 1][y];
            break;
        case 3: // left
            if (y > 0 && !cells[x][y - 1].visited)
                return &cells[x][y - 1];
            break;
        }
        return nullptr;
    }

    void removeWall(Cell *a, Cell *b)
    {
        int dx = a->x - b->x;
        if (dx == 1)
        {
            a->walls[0] = false;
            b->walls[2] = false;
        }
        else if (dx == -1)
        {
            a->walls[2] = false;
            b->walls[0] = false;
        }
        int dy = a->y - b->y;
        if (dy == 1)
        {
            a->walls[3] = false;
            b->walls[1] = false;
        }
        else if (dy == -1)
        {
            a->walls[1] = false;
            b->walls[3] = false;
        }
    }

    bool findPath(int x, int y)
    {
        if (x == rows - 1 && y == cols - 1)
        {
            path[x][y] = true;
            return true;
        }
        if (x < 0 || y < 0 || x >= rows || y >= cols)
            return false;
        if (cells[x][y].pathVisited)
            return false;

        cells[x][y].pathVisited = true;

        if (y < cols - 1 && !cells[x][y].walls[1] && findPath(x, y + 1))
        {
            path[x][y] = true;
            return true;
        }

        return false;
    }

    void printMaze()
    {
        for (int i = 0; i < rows; i++)
        {
            // Print top walls
            for (int j = 0; j < cols; j++)
            {
                std::cout << "+";
                std::cout << (cells[i][j].walls[0] ? "---" : "   ");
            }
            std::cout << "+\n";
            // Print cells and right walls
            for (int j = 0; j < cols; j++)
            {
                std::cout << (cells[i][j].walls[3] ? "|" : " ");
                std::cout << (path[i][j] ? " . " : "   ");
            }
            std::cout << "|\n";
        }
        // Print bottom walls
        for (int j = 0; j < cols; j++)
        {
            std::cout << "+---";
        }
        std::cout << "+\n";
    }
};

#endif