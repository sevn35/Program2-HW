#include "employee.h"

DeptInfo::DeptInfo()
{
    totalSalary = 0;
    size = 0;
};

DeptInfo::DeptInfo(string a, int b, double c){
    Department = a;
    size = b;
    totalSalary = c;
};