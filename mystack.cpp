#include <iostream>
#include <vector>
using namespace std;

class Stack
{
public:
    Stack();
    bool isEmpty() const;
    // returns true if stack has no elements stored
    int top() const;
    // returns element from top of the stack
    // throws std::runtime_error(is empty")
    int pop();
    // returns element from top of the stack and removes it
    // throws std::runtime_error("stack is empty")
    void push(int);
    // puts a new element on top of the stack
    std::string toString() const;
    // returns the contents of the stack in the format [top, next, , bottom]
    // e.g.: push(l), push(2), toString() -> [2, I]
private:
    std::vector<int> elements;
};

Stack::Stack()
{
    elements.clear();
}
bool Stack::isEmpty() const
{
    return elements.empty();
}
int Stack::top() const
{
    if (isEmpty())
    {
        throw std::runtime_error("stack is empty");
    }
    return elements.back();
}
int Stack::pop()
{
    if (isEmpty())
    {
        throw std::runtime_error("stack is empty");
    }
    int temp = elements.back();
    elements.pop_back();
    return temp;
}
void Stack::push(int element)
{
    elements.push_back(element);
}
std::string Stack::toString() const
{
    std::string result = "[";
    for (int i = 0; i < elements.size(); ++i)
    {
        result += std::to_string(elements[i]);
        if (i != elements.size() - 1)
        {
            result += ", ";
        }
    }
    result += "]";
    return result;
}
int main()
{
    Stack stack;
    std::string command;
    while (std::cin >> command)
    {
        if (command == "end")
        {
            break;
        }
        if (command == "push")
        {
            int element;
            std::cin >> element;
            stack.push(element);
        }
        if (command == "pop")
        {
            try
            {
                std::cout << stack.pop() << std::endl;
            }
            catch (std::runtime_error e)
            {
                std::cout << e.what() << std::endl;
            }
        }
        if (command == "list")
        {
            std::cout << stack.toString() << std::endl;
        }
        if (command == "top")
        {
            try
            {
                std::cout << stack.top() << std::endl;
            }
            catch (std::runtime_error e)
            {
                std::cout << e.what() << std::endl;
            }
        }
        if (command == "empty")
        {
            std::cout << stack.isEmpty() << std::endl;
        }
    }
    return 0;
}