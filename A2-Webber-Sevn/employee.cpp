#include "employee.h"

employee::employee()
{
    ec = 's';
    salary = 0;


};

 employee::employee(char ss, string sn, string f, string l, string o, string j , double c)
 {
    cout << "values picked";
    ec = ss;
    ssn = sn;
    firstname = f;
    lastname = l;
    ops = o;
    job = j;
    salary = c;

 };