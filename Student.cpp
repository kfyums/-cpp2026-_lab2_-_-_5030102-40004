#include "Student.h"
#include <cstdlib>
#include <cmath>

Student::Student(std::string name, StudentType type)
{
    this->name = name;
    this->type = type;
}

void Student::solve(double a, double b, double c, double& x1, double& x2) const
{
    const double e = 1e-9;
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
    double real_x1 = (-b + std::sqrt(D)) / (2 * a);
    double real_x2 = (-b - std::sqrt(D)) / (2 * a);
    if (type == StudentType::good)
    {
        x1 = real_x1;
        x2 = real_x2;
    }
    else if (type == StudentType::medium)
    {
        if (std::rand() % 2 == 0)
        {
            x1 = real_x1;
            x2 = real_x2;
        }
        else
        {
            x1 = x2 = 0;
        }
    }
    else 
    {
        x1 = x2 = 0;
    }
}
