#include "Student.h"
#include <cstdlib>

Student::Student(std::string name, StudentType type) 
{
    this->name = name;
    this->type = type;
}

void Student::solve(double real_x1, double real_x2, double& x1, double& x2) const 
{
    if (type == StudentType::good) 
    {
        x1 = real_x1;
        x2 = real_x2;
        return;
    }
    if (type == StudentType::medium) 
    {
        if (std::rand() % 2 == 0) 
        {
            x1 = real_x1;
            x2 = real_x2;
        }
        else {
            x1 = x2 = 0;
        }
        return;
    }
    x1 = x2 = 0;
}
