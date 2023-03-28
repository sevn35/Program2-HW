#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Employee{
private:
    string first, last, ssn;
    float salary;
public:
    Employee();
    Employee(string, string, string, float);
    ~Employee();
    void print(ostream&);
};
#endif