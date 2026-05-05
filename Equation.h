#pragma once
class Equation 
{
public:
    double a, b, c;
    Equation(double a, double b, double c);
    void solve(double& x1, double& x2) const;
};
