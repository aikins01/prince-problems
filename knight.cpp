#include <iostream>
#include <sstream>
#include <vector>
#include <exception>

const std::vector<std::vector<int>> knightMoves = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {2, 1}, {2, -1}, {1, -2}, {1, 2}};
const int UNVISITED = -1;

class InputException : public std::exception
{
public:
    explicit InputException(const std::string &message) : msg_(message) {}
    const char *what() const noexcept override { return msg_.c_str(); }

private:
    std::string msg_;
};

bool isStepValid(const std::vector<std::vector<int>> &matrix, const std::vector<int> &origin, const std::vector<int> &move)
{
    int newX = origin[0] + move[0];
    int newY = origin[1] + move[1];
    const int matrixSize = matrix.size();

    if ((newX < 0) || (newX >= matrixSize))
        return false;
    if ((newY < 0) || (newY >= matrixSize))
        return false;

    return (matrix[newX][newY] == UNVISITED);
}

bool findKnightTour(std::vector<std::vector<int>> &matrix, const std::vector<int> &origin, const std::vector<int> &destination)
{
    if ((origin[0] == destination[0]) && (origin[1] == destination[1]))
        return true;

    for (const auto &move : knightMoves)
    {
        if (isStepValid(matrix, origin, move))
        {
            std::vector<int> nextStep = {origin[0] + move[0], origin[1] + move[1]};
            matrix[nextStep[0]][nextStep[1]] = matrix[origin[0]][origin[1]] + 1;
            bool journeySuccess = findKnightTour(matrix, nextStep, destination);
            if (journeySuccess)
                return true;
            matrix[nextStep[0]][nextStep[1]] = UNVISITED;
        }
    }
    return false;
}

int extractNumber(const std::string &input)
{
    int num;
    std::istringstream stream(input);
    stream >> num;
    if (stream.fail())
        throw InputException("Invalid number format");
    return num;
}

std::vector<int> extractPosition(const std::string &input, int matrixSize)
{
    std::vector<int> position(2);
    std::istringstream stream(input);
    char columnChar;
    char maxChar = 'a' + matrixSize - 1;
    stream >> columnChar;
    if ((columnChar < 'a') || (columnChar > maxChar))
        throw InputException("Invalid column character");
    position[0] = columnChar - 'a';
    stream >> position[1];
    if (stream.fail())
        throw InputException("Invalid row number");
    if ((position[1] < 1) || (position[1] > matrixSize))
        throw InputException("Row number out of range");
    position[1]--;
    return position;
}

std::string positionToString(const std::vector<int> &s)
{
    std::string str;
    str += (s[0] + 'a');
    str += std::to_string(s[1] + 1);
    return str;
}

void displayJourney(const std::vector<std::vector<int>> &matrix, int maxStep)
{
    for (int step = 0; step <= maxStep; step++)
    {
        for (int c = 0; c < matrix.size(); c++)
        {
            for (int r = 0; r < matrix.size(); r++)
            {
                if (matrix[c][r] == step)
                {
                    std::cout << positionToString({c, r}) << ' ';
                }
            }
        }
    }
    std::cout << std::endl;
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cout << "Invalid parameter list\n";
        return 1;
    }

    try
    {
        const int MAX_SIZE = 26;
        int matrixSize = extractNumber(argv[1]);
        if ((matrixSize < 1) || (matrixSize > MAX_SIZE))
            throw InputException("Invalid matrix size");

        std::vector<int> startPosition = extractPosition(argv[2], matrixSize);
        std::vector<int> targetPosition = extractPosition(argv[3], matrixSize);

        std::vector<std::vector<int>> matrix(matrixSize, std::vector<int>(matrixSize, UNVISITED));
        matrix[startPosition[0]][startPosition[1]] = 0;
        bool journeySuccess = findKnightTour(matrix, startPosition, targetPosition);
        if (journeySuccess)
        {
            int steps = matrix[targetPosition[0]][targetPosition[1]];
            displayJourney(matrix, steps);
        }
        else
        {
            std::cout << "Could not find a knight's tour\n";
        }
    }
    catch (InputException &e)
    {
        std::cout << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}