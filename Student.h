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
private:
    std::string name;
    StudentType type;
public:
    Student(const std::string& name, StudentType type);
    const std::string& getName() const;
    void solve(double a, double b, double c, double& x1, double& x2) const;
};
