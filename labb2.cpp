#pragma warning (disable:4996)
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <locale.h>
#include <stdio.h>
using namespace std;

struct Mail {
    char name[20];
    double a, b, c;
    double x1, x2;
};

void solve(double a, double b, double c, double& x1, double& x2)
{
    double D = b * b - 4 * a * c;
    if (D < 0)
    {
        x1 = x2 = 0;
        return;
    }
    x1 = (-b + sqrt(D)) / (2 * a);
    x2 = (-b - sqrt(D)) / (2 * a);
}

void student(int type, double real_x1, double real_x2, double& x1, double& x2)
{
    if (type == 0)
    {
        x1 = real_x1;
        x2 = real_x2;
    }
    else if (type == 1)
    {
        if (rand() % 2 == 0)
        {
            x1 = real_x1;
            x2 = real_x2;
        }
        else
        {
            x1 = 0;
            x2 = 0;
        }
    }
    else
    {
        x1 = 0;
        x2 = 0;
    }
}

bool check(double x1, double x2, double real_x1, double real_x2)
{
    return ((abs(x1 - real_x1) < 0.001 && abs(x2 - real_x2) < 0.001) || (abs(x1 - real_x2) < 0.001 && abs(x2 - real_x1) < 0.001));
}

void copyName(char dest[], const char src[])
{
    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

int main() {
    srand(time(0));
    setlocale(LC_CTYPE, "Russian");
    const char names[3][20] = { "Иван", "Петр", "Саша" };
    int type[3] = { 0, 1, 2 };
    int correct[3] = { 0, 0, 0 };
    Mail mails[100];
    int mailCount = 0;
    FILE* f = fopen("input.txt", "r");
    if (f == NULL) {
        cout << "ошибка открытия\n";
        return 1;
    }
    double a, b, c;
    while (fscanf(f, "%lf %lf %lf", &a, &b, &c) == 3) {
        double real_x1, real_x2;
        solve(a, b, c, real_x1, real_x2);
        for (int j = 0; j < 3; j++) {
            double x1, x2;
            student(type[j], real_x1, real_x2, x1, x2);
            copyName(mails[mailCount].name, names[j]);
            mails[mailCount].a = a;
            mails[mailCount].b = b;
            mails[mailCount].c = c;
            mails[mailCount].x1 = x1;
            mails[mailCount].x2 = x2;
            mailCount++;
        }
    }
    fclose(f);
    for (int i = 0; i < mailCount; i++) {
        double real_x1, real_x2;
        solve(mails[i].a, mails[i].b, mails[i].c, real_x1, real_x2);
        for (int j = 0; j < 3; j++) {
            int k = 0;
            bool same = true;
            while (names[j][k] != '\0' || mails[i].name[k] != '\0')
            {
                if (names[j][k] != mails[i].name[k])
                {
                    same = false;
                    break;
                }
                k++;
            }
            if (same) {
                if (check(mails[i].x1, mails[i].x2, real_x1, real_x2)) {
                    correct[j]++;
                }
            }
        }
    }
    cout << "\nтаблица успеваемости:\n";
    cout << "имя\tрешено\n";
    for (int i = 0; i < 3; i++) {
        cout << names[i] << "\t" << correct[i] << endl;
    }
    return 0;
}