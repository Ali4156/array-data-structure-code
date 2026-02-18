#include <iostream>
#include "Department.h"
using namespace std;

int main()
{
    Department d1(123, "Fc", 5);

    d1.hire(101, "Ali");
    d1.hire(102, "zaka");
    

    d1.display();
    d1.fire(101);

    cout << "after fire:";
    d1.display();

 
}