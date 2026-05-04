#pragma once
#include <string>

enum class StudentType 
{
    good,
    medium,
    bad
};

class Student 
{
public:
    std::string name;
    StudentType type;
    Student(std::string name, StudentType type);
    void solve(double a, double b, double c, double& x1, double& x2) const;
};
