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
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <iomanip>
#include <random>
#include <cassert>
#include <complex>
#include <bits/stdc++.h>

using namespace std;

class Cell {
public:
    int row, col;
    Cell(int r, int c) : row(r), col(c) {}
};

class Maze {
public:
    int rows, cols;
    vector<vector<int>> maze;
    vector<Cell> path;
    Maze(int r, int c) : rows(r), cols(c) {
        maze.resize(rows);
        for (int i = 0; i < rows; i++) {
            maze[i].resize(cols);
        }
    }
    void generate() {
        int r = 0, c = 0;
        path.push_back(Cell(r, c));
        while (r != rows - 1 || c != cols - 1) {
            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, 1, 0, -1};
            int nr = r + dr[rand() % 4];
            int nc = c + dc[rand() % 4];
            if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) {
                continue;
            }
            if (maze[nr][nc] == 0) {
                maze[r][c] |= (1 << (rand() % 4));
                maze[nr][nc] |= (1 << ((rand() % 4) + 4));
                path.push_back(Cell(nr, nc));
                r = nr;
                c = nc;
            }
        }
    }
    void print() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (i == 0 && j == 0) {
                    cout << "S";
                } else if (i == rows - 1 && j == cols - 1) {
                    cout << "E";
                } else {
                    cout << (maze[i][j] & 8 ? ' ' : '+');
                    cout << (maze[i][j] & 4 ? ' ' : '+');
                }
            }
            cout << endl;
            for (int j = 0; j < cols; j++) {
                cout << (maze[i][j] & 2 ? ' ' : '+');
                cout << (maze[i][j] & 1 ? ' ' : '+');
                cout << (maze[i][j] & 16 ? ' ' : '+');
            }
            cout << endl;
        }
    }
};


int main(int argc, char *argv[]) {
    if (argc == 3) {
        srand(atoi(argv[2]));
    } else if (argc != 2) {
        cout << "Usage: " << argv[0] << " <rows> <cols> [<seed>]" << endl;
        return 1;
    }
    int rows = atoi(argv[1]);
    int cols = atoi(argv[2]);
    Maze m(rows, cols);
    m.generate();
    m.print();
    return 0;
}