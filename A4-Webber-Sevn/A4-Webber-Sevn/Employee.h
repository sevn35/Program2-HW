#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

class Employee{
   
private:
    string ec;
    string ssn; 
	string firstname; 
	string lastname;
    string ops;
    string job;
	string salary;

public:
    Employee();
    Employee(const string&); 
    void display(ostream& out);
    ~Employee(); 
                
};


