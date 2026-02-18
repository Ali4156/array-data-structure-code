#include "Employee.h"
#include "Department.h"
#include <iostream>
using namespace std;


Employee::Employee() {
    Emp_Id = 0;
    Emp_Name = "";
}

Employee::Employee(int id, string name) {
    Emp_Id = id;
    Emp_Name = name;
}

int Employee::getEmp_Id() {
    return Emp_Id;
}

void Employee::setEmp_Id(int id) {
    Emp_Id = id;
}

string Employee::getEmp_Name() {
    return Emp_Name;
}

void Employee::setEmp_Name(string name) {
    Emp_Name = name;
}


// ================= Department Implementation =================

Department::Department()
{
    Dep_Id = -1;
    Dep_Name = "";
    capacity = 5;
    currently_Employed = 0;
    Employees = new Employee[capacity];
}

Department::Department(int Dep_Id, string Dep_Name, int capacity)
{
    this->Dep_Id = Dep_Id;
    this->Dep_Name = Dep_Name;
    this->capacity = capacity;
    currently_Employed = 0;
    Employees = new Employee[capacity];
}

int Department::getDep_Id() { return Dep_Id; }
void Department::setDep_Id(int Dep_Id) { this->Dep_Id = Dep_Id; }

string Department::getDep_Name() { return Dep_Name; }
void Department::setDep_Name(string Dep_Name) { this->Dep_Name = Dep_Name; }

int Department::getcapacity() { return capacity; }
void Department::setcapacity(int capacity) { this->capacity = capacity; }

int Department::getcurrently_Employed() { return currently_Employed; }
void Department::setcurrently_Employed(int currently_Employed) {
    this->currently_Employed = currently_Employed;
}

void Department::hire(int Emp_Id, string Emp_Name)
{
    if (currently_Employed == capacity)
        resize();

    Employees[currently_Employed].setEmp_Id(Emp_Id);
    Employees[currently_Employed].setEmp_Name(Emp_Name);
    currently_Employed++;
}

void Department::resize()
{
    capacity += 5;
    Employee* newEmployees = new Employee[capacity];

    for (int i = 0; i < currently_Employed; i++)
    {
        newEmployees[i].setEmp_Id(Employees[i].getEmp_Id());
        newEmployees[i].setEmp_Name(Employees[i].getEmp_Name());
    }

    delete[] Employees;
    Employees = newEmployees;
}

int Department::search(int id)
{
    for (int i = 0; i < currently_Employed; i++)
    {
        if (Employees[i].getEmp_Id() == id)
            return i;
    }
    return -1;
}

void Department::fire(int ID)
{
    int index = search(ID);

    if (index == -1)
    {
        cout << "Employee Not Found!" << endl;
        return;
    }

    shift(index);
    currently_Employed--;
}

void Department::shift(int index)
{
    for (int i = index; i < currently_Employed - 1; i++)
    {
        Employees[i].setEmp_Id(Employees[i + 1].getEmp_Id());
        Employees[i].setEmp_Name(Employees[i + 1].getEmp_Name());
    }
}

void Department::display()
{
    cout << "Department Name "
        << Dep_Name << endl;

    cout << " Department ID   "
        << Dep_Id << endl;

    cout << "Employees "
        << currently_Employed << endl << endl;

    for (int i = 0; i < currently_Employed; i++)
    {
        cout << Employees[i].getEmp_Id() << "  \t"
            << Employees[i].getEmp_Name() << endl;
    }

    
}