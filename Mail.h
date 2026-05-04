#pragma once
#include <string>
struct Mail
{
    std::string name;
    double a, b, c;
    double x1, x2;
    Mail(std::string name, double a, double b, double c, double x1, double x2) : name(name), a(a), b(b), c(c), x1(x1), x2(x2) {}
};
