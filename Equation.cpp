#include "Equation.h"
#include <cmath>

Equation::Equation(double a, double b, double c) 
{
    this->a = a;
    this->b = b;
    this->c = c;
}

void Equation::solve(double& x1, double& x2) const 
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
    x1 = (-b + std::sqrt(D)) / (2 * a);
    x2 = (-b - std::sqrt(D)) / (2 * a);
}
