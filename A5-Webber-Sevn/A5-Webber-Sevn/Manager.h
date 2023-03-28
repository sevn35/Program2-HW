#ifndef MANAGER_H
#define MANAGER_H

#include "Employee.h"

class Manager : public Employee{
private:
    string department;
public:
    Manager();
    Manager(string, string, string, float, string);
    ~Manager();
    void print(ostream&);
};
#endif