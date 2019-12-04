#include <iostream>
#include <vector>


typedef struct student
{
    std::string first_name;
    std::string family_name;
    int matriculation_number;
} Student;

int main()
{
    std::vector<Student> students;
    int number;
    std::cout << "Enter number of students that you want to create: ";
    std::cin >> number;

    for (int i = 0; i < number; i++) {
        Student student;
        std::cout << "Enter a first name of the student: ";
        std::cin >> student.first_name;
        std::cout << "Enter a family name of the student: ";
        std::cin >> student.family_name;
        std::cout << "Enter a marticulation number of the student: ";
        std::cin >> student.matriculation_number;
        students.emplace_back(student);
    }

    for (int i = 0; i < students.size(); i++) {
        for (int j = i + 1; j < students.size(); j++) {
            if (students[i].matriculation_number == students[j].matriculation_number) {
                students.erase(students.begin() + j);
            }
        }
    }

    for (auto student : students) {
        std::cout << student.first_name << " " << student.family_name << " - " << student.matriculation_number << "\n";
    }

    return 0;
}