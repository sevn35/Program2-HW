#pragma once
#include <iostream>
#include <string>
using namespace std;

struct employee{

    char ec;
    string ssn; 
	string firstname; 
	string lastname;
    string ops;
    string job;
	double salary;

    employee();

    employee(char , string , string , string , string, string, double); 
                
};

struct DeptInfo{

    string Department; 
    int size;
	double totalSalary;

    DeptInfo();

    DeptInfo(string , int, double); 
                
};

