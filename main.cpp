#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <locale.h>
#include "Equation.h"
#include "Student.h"
#include "Mail.h"
#include <map>

bool check(double x1, double x2, double rx1, double rx2) 
{
    return ((std::abs(x1 - rx1) < 0.001 && std::abs(x2 - rx2) < 0.001) || (std::abs(x1 - rx2) < 0.001 && std::abs(x2 - rx1) < 0.001));
}

int main() 
{
    setlocale(LC_CTYPE, "Russian");
    std::srand((unsigned)std::time(nullptr));
    std::vector<Student> students;
    students.push_back(Student("Иван", StudentType::good));
    students.push_back(Student("Петр", StudentType::medium));
    students.push_back(Student("Саша", StudentType::bad));
    std::map<std::string, int> correct;
    for (const auto& s : students)
    {
        correct[s.getName()] = 0;
    }
    std::vector<Mail> mails;
    std::ifstream file("input.txt");
    if (!file) 
    {
        std::cout << "Ошибка открытия\n";
        return 1;
    }
    double a, b, c;
    while (file >> a >> b >> c)
    {
        for (const auto& student : students)
        {
            double x1, x2;
            student.solve(a, b, c, x1, x2);
            mails.emplace_back(student.getName(), a, b, c, x1, x2);
        }
    }
    for (const auto& mail : mails)
    {
        Equation eq(mail.a, mail.b, mail.c);
        double rx1, rx2;
        eq.solve(rx1, rx2);
        if (check(mail.x1, mail.x2, rx1, rx2))
        {
            correct[mail.name]++;
        }
    }
    std::cout << "\nТаблица:\n";
    std::cout << "Имя\tРешено\n";
    for (const auto& s : students)
    {
        std::cout << s.name << "\t" << correct[s.getName()] << "\n";
    }
    return 0;
}
