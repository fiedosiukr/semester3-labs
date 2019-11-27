#include <iostream>


template<class T>
class Calculator
{
    public:
        Calculator(T t_a, T t_b) : a(t_a), b(t_b) {} 
        T addition() { return a + b; }
        T multiplication() { return a * b; }
        T maximum() { return a > b ? a : b; }

    private:
        T a, b;

};

int main()
{
    int a, b;
    std::cout << "Enter first integer: ";
    std::cin >> a;
    std::cout << "Enter second integer: ";
    std::cin >> b;
    Calculator<int> intulator(a, b);

    std::cout << "Sum of integers is: " << intulator.addition() << "\n";
    std::cout << "Maximum of integers is: " << intulator.maximum() << "\n";
    std::cout << "Multiplication of integers is: " << intulator.multiplication() << "\n";
    
    char c, d;
    std::cout << "Enter first char: ";
    std::cin >> c;
    std::cout << "Enter second char: ";
    std::cin >> d;
    Calculator<char> charculator(c, d);

    std::cout << "Sum of characters is: " << charculator.addition() << "\n";
    std::cout << "Maximum of characters is: " << charculator.maximum() << "\n";
    std::cout << "Multiplication of characters is: " << charculator.multiplication() << "\n";
    
    float e, f;
    std::cout << "Enter first float number: ";
    std::cin >> e;
    std::cout << "Enter second float number: ";
    std::cin >> f;
    Calculator<float> floatculator(e, f);
    
    std::cout << "Sum of floats is: " << floatculator.addition() << "\n";
    std::cout << "Maximum of floats is: " << floatculator.maximum() << "\n";
    std::cout << "Multiplication of floats is: " << floatculator.multiplication() << "\n";
    

    return 0;
}