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
    void solve(double real_x1, double real_x2, double& x1, double& x2) const;
};
