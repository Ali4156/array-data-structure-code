#pragma once
#include <string>
using namespace std;

class Employee {
private:
    int Emp_Id;
    string Emp_Name;

public:
    Employee();
    Employee(int, string);

    int getEmp_Id();
    void setEmp_Id(int);

    string getEmp_Name();
    void setEmp_Name(string);
};