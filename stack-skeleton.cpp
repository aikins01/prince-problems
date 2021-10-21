#include <iostream>
#include <limits>
#include <vector>

class Stack {
    public:
        Stack();
        bool isEmpty() const;
        int top() const;
        int pop();
        void push(int i);
        std::string toString() const;
    private:
        std::vector<int> elements;
};

//
// your implementation of Stack goes here
//
//

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
    for (int i = elements.size()-1; i < elements.size(); --i)
    {
        result += std::to_string(elements[i]);
        if (i != 0)
        {
            result += ", ";
        }
    }
    result += "]";
    return result;
}



int main() {
    Stack stack;
    
    while (true) {
        try {
            std::cout << "stack> " << std::endl;
            
            std::string command;
            std::cin >> command;
            
            if ( (command.compare("end") == 0) || std::cin.eof() ){
                break;
            } else if (command.compare("top") == 0) {
                std::cout << stack.top() << std::endl;
            } else if (command.compare("pop") == 0) {
                std::cout << stack.pop() << std::endl;
            } else if (command == "push") {
                if ( std::cin.eof() ) break;
                int i;
                std::cin >> i;
                bool failed = std::cin.fail();
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                if ( failed ){
                  throw std::runtime_error("not a number");
                }
                stack.push(i);
            } else if ( command.compare("list") == 0){
                std::cout << stack.toString() << std::endl;;
            } else {
                throw std::runtime_error("invalid command");
            }
        } catch (std::runtime_error& e) {
            std::cout << "error: " << e.what() << std::endl;
        }
    }
    
    return 0;
}