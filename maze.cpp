#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <climits>
#include <cassert>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <numeric>
#include <bits/stdc++.h>

using namespace std;

class Cell {
public:
    Cell() {
        visited = false;
        blocked = false;
    }
    bool visited;
    bool blocked;
};

class Maze {
public:
    Maze(int rows, int cols) {
        this->rows = rows;
        this->cols = cols;
        cells = new Cell[rows * cols];
    }
    ~Maze() {
        delete[] cells;
    }
    void generate() {
        srand(time(NULL));
        for (int i = 0; i < rows * cols; i++) {
            cells[i].visited = false;
            cells[i].blocked = false;
        }
        int current = rand() % (rows * cols);
        cells[current].visited = true;
        while (true) {
            int neighbours[4];
            neighbours[0] = current - cols;
            neighbours[1] = current + cols;
            neighbours[2] = current - 1;
            neighbours[3] = current + 1;
            int num_neighbours = 0;
            for (int i = 0; i < 4; i++) {
                if (neighbours[i] >= 0 && neighbours[i] < rows * cols) {
                    if (!cells[neighbours[i]].visited) {
                        num_neighbours++;
                    }
                }
            }
            if (num_neighbours == 0) {
                break;
            }
            int next = rand() % num_neighbours;
            int count = 0;
            for (int i = 0; i < 4; i++) {
                if (neighbours[i] >= 0 && neighbours[i] < rows * cols) {
                    if (!cells[neighbours[i]].visited) {
                        if (count == next) {
                            if (i == 0) {
                                cells[current].blocked = true;
                                cells[neighbours[i]].blocked = true;
                            } else if (i == 1) {
                                cells[current].blocked = true;
                                cells[neighbours[i]].blocked = true;
                            } else if (i == 2) {
                                cells[current].blocked = true;
                            } else if (i == 3) {
                                cells[current].blocked = true;
                            }
                            cells[neighbours[i]].visited = true;
                            current = neighbours[i];
                            break;
                        }
                        count++;
                    }
                }
            }
        }
    }
    void print() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (cells[i * cols + j].blocked) {
                    cout << "---";
                } else {
                    cout << "   ";
                }
            }
            cout << endl;
            for (int j = 0; j < cols; j++) {
                if (cells[i * cols + j].blocked) {
                    cout << "|";
                } else {
                    cout << " ";
                }
                if (cells[i * cols + j].visited) {
                    cout << ".";
                } else {
                    cout << " ";
                }
            }
            cout << endl;
        }
        for (int j = 0; j < cols; j++) {
            if (cells[(rows - 1) * cols + j].blocked) {
                cout << "---";
            } else {
                cout << "   ";
            }
        }
        cout << endl;
    }
private:
    int rows;
    int cols;
    Cell* cells;
};

int main(int argc, char* argv[]) {
    int rows = atoi(argv[1]);
    int cols = atoi(argv[2]);
    if (argc == 4) {
        srand(atoi(argv[3]));
    } else {
        srand(time(NULL));
    }
    Maze maze(rows, cols);
    maze.generate();
    maze.print();
    return 0;
}