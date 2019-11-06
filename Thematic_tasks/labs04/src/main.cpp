#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>


class MyException : public std::exception
{
    public:
        MyException(const char* t_message) : m_message(t_message) {}
        const char* what() { return m_message; }
    private:
        const char* m_message;
};

int get_input()
{
    int x;

    std::cin >> x;

    if (std::cin.fail()) {
        throw MyException("Char has to be an integer!");  
    } else {
        return x;
    }
}

void exception_handler(int &x)
{
    try 
    {
        x = get_input();
    } catch (MyException &e) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << e.what() << "\n";
        exception_handler(x);
    }
}

int main()
{
    
    int x;
    
    std::cout << "Enter an integer number: ";
    exception_handler(x);
    std::cout << "Number is: " << x << "\n";
    return 0;
}