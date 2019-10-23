#include <iostream>

class Person {
    public:
        void speech() {
            std::cout << "I'm a person.\n";
        }
};

class Mother : virtual public Person {
    public:
        void say() {
            std::cout << "I'm a mother.\n";
        }
};

class Father : virtual public Person {
    public:
        void tell() {
            std::cout << "I'm a father.\n";
        }
};

class Child : public Mother, public Father {
    public:
        Child() {
            std::cout << "I'm a child.\n";
        }
};

int main() {
    Child child;
    child.speech();

    return 0;
}