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
    std::vector<int> correct(students.size(), 0);
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
        Equation eq(a, b, c);
        double rx1, rx2;
        eq.solve(rx1, rx2);
        for (int i = 0; i < students.size(); i++)
        {
            double x1, x2;
            students[i].solve(rx1, rx2, x1, x2);
            Mail m;
            m.name = students[i].name;
            m.a = a;
            m.b = b;
            m.c = c;
            m.x1 = x1;
            m.x2 = x2;
            mails.push_back(m);
        }
    }
    for (int i = 0; i < mails.size(); i++) {
        Equation eq(mails[i].a, mails[i].b, mails[i].c);
        double rx1, rx2;
        eq.solve(rx1, rx2);
        for (int j = 0; j < students.size(); j++) 
        {
            if (students[j].name == mails[i].name) 
            {
                if (check(mails[i].x1, mails[i].x2, rx1, rx2)) 
                {
                    correct[j]++;
                }
            }
        }
    }
    std::cout << "\nТаблица:\n";
    std::cout << "Имя\tРешено\n";
    for (int i = 0; i < students.size(); i++) 
    {
        std::cout << students[i].name << "\t" << correct[i] << "\n";
    }
    return 0;
}
