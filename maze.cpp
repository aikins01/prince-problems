#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Maze {
public:
    Maze(int rows, int cols, int seed = 0) {
        srand(seed);
        for (int i = 0; i < rows; i++) {
            vector<bool> row;
            for (int j = 0; j < cols; j++) {
                row.push_back(rand() % 2);
            }
            maze.push_back(row);
        }
    }

    void print() {
        for (int i = 0; i < maze.size(); i++) {
            for (int j = 0; j < maze[i].size(); j++) {
                if (i == 0 && j == 0) {
                    cout << "+";
                } else if (i == maze.size() - 1 && j == maze[i].size() - 1) {
                    cout << "+";
                } else if (i == 0) {
                    cout << "---";
                } else if (j == 0) {
                    cout << "|";
                } else if (maze[i][j]) {
                    cout << "   ";
                } else {
                    cout << " . ";
                }
            }
            cout << endl;
        }
    }

    bool findPath(int fromRow, int fromCol, int toRow, int toCol) {
        if (fromRow == toRow && fromCol == toCol) {
            return true;
        }
        maze[fromRow][fromCol] = true;
        vector<pair<int, int>> neighbours = getNeighbours(fromRow, fromCol);
        for (int i = 0; i < neighbours.size(); i++) {
            int nRow = neighbours[i].first;
            int nCol = neighbours[i].second;
            if (maze[nRow][nCol] == false) {
                if (findPath(nRow, nCol, toRow, toCol)) {
                    return true;
                }
            }
        }
        maze[fromRow][fromCol] = false;
        return false;
    }

    vector<pair<int, int>> getNeighbours(int row, int col) {
        vector<pair<int, int>> neighbours;
        if (row > 0) {
            neighbours.push_back(make_pair(row - 1, col));
        }
        if (row < maze.size() - 1) {
            neighbours.push_back(make_pair(row + 1, col));
        }
        if (col > 0) {
            neighbours.push_back(make_pair(row, col - 1));
        }
        if (col < maze[row].size() - 1) {
            neighbours.push_back(make_pair(row, col + 1));
        }
        return neighbours;
    }

private:
    vector<vector<bool>> maze;
};

int main(int argc, char *argv[]) {
    if (argc == 3) {
        int rows = atoi(argv[1]);
        int cols = atoi(argv[2]);
        Maze m(rows, cols);
        m.print();
    } else if (argc == 4) {
        int rows = atoi(argv[1]);
        int cols = atoi(argv[2]);
        int seed = atoi(argv[3]);
        Maze m(rows, cols, seed);
        m.print();
    } else {
        cout << "Usage: " << argv[0] << " <rows> <cols> [<seed>]" << endl;
    }
    return 0;
}