#include <iostream>

int main()
{
    const std::string PROMPT = "Enter the expression: ";
    bool check = true;
    while (check)
    {
        char operation;
        double operand1, operand2, result;
        std::cout << PROMPT;
        std::cin >> operation;
        if (operation == 'q')
        {
            check = false;
        }
        else
        {
            check = true;
        }

        if (check)
        {

            std::cin >> operand1 >> operand2;
            switch (operation)
            {
            case '+':
                result = operand1 + operand2;
                break;

            case '-':
                result = operand1 - operand2;
                break;

            case '*':
                result = operand1 * operand2;
                break;

            case '/':
                result = operand1 / operand2;
                break;
            }

            std::cout << operand1 << " " << operation << " " << operand2 << " " << '=' << " " << result << std::endl;
        }
    }

    return 0;
}