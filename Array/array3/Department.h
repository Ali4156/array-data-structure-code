#pragma once
#include <string>
#include "Employee.h"
using namespace std;

class Department {
private:
    int Dep_Id;
    string Dep_Name;
    int capacity;
    int currently_Employed;
    Employee* Employees;

public:
    Department();
    Department(int, string, int);

    int getDep_Id();
    void setDep_Id(int);

    string getDep_Name();
    void setDep_Name(string);

    int getcapacity();
    void setcapacity(int);

    int getcurrently_Employed();
    void setcurrently_Employed(int);

    void hire(int, string);
    void fire(int);

    void resize();
    void shift(int);
    int search(int);

    void display();
};