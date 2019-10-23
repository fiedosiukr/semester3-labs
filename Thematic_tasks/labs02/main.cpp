#include <iostream>

class Person {
    public:
        void speech() {
            std::cout << "I'm a person.\n";
        }
};

class Mother : public Person {
    public:
        void speech() {
            std::cout << "I'm a mother.\n";
        }
};

class Father : public Person {
    public:
        void speech() {
            std::cout << "I'm a father.\n";
        }
};

class Child : public Mother, public Father {
    public:
        Child() {
            std::cout << "I'm a child.";
        }
};

int main() {
    Child child;
    child.speech();

    return 0;
}