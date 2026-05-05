#include "Student.h"
#include <cstdlib>
#include <cmath>
Student::Student(const std::string& name, StudentType type) 
{
    this->name = name;
    this->type = type;
}
const std::string& Student::getName() const
{
    return name;
}
void Student::solve(double a, double b, double c, double& x1, double& x2) const
{
    const double e = 1e-9;
    bool correct = false;
    if (type == StudentType::good)
        correct = true;
    else if (type == StudentType::medium)
        correct = (std::rand() % 2 == 0);
    else
        correct = false;
    if (!correct)
    {
        x1 = x2 = 0;
        return;
    }
    if (std::abs(a) < e)
    {
        x1 = x2 = 0;
        return;
    }
    double D = b * b - 4 * a * c;
    if (D < 0)
    {
        x1 = x2 = 0;
        return;
    }
    x1 = (-b + std::sqrt(D)) / (2 * a);
    x2 = (-b - std::sqrt(D)) / (2 * a);
}
