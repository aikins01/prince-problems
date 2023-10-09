#include <iostream>
#include <vector>
#include <random>
#include <stack>
#include "maze.h"

int main(int argc, char *argv[])
{
    if (argc < 3 || argc > 4)
    {
        std::cout << "Invalid number of arguments\n";
        return 1;
    }

    int rows = std::stoi(argv[1]);
    int cols = std::stoi(argv[2]);

    Maze maze(rows, cols);

    if (argc == 4)
    {
        int seed = std::stoi(argv[3]);
        std::srand(seed);
    }

    maze.generateMaze();
    maze.findPath(0, 0);
    maze.printMaze();

    return 0;
}