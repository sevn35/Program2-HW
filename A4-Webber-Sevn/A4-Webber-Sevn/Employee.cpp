#include "Employee.h"


Employee::Employee()
{
    ec = "s";
    salary = "0";


};

Employee::Employee(const string& s){
    cout << "       Employee::Employee(const string& s)called"<<"   :" << this << endl;
    istringstream ss(s); //Creates a stream from s to assignt values
    ss >> ec >> ssn >> firstname >> lastname >> ops >> job >> salary;
}

void Employee::display(ostream& out){ //This block displays each value with proper spacing
    out <<left<<setw(5)<<ec<<setw(12)<<ssn<<setw(12)<<firstname<<setw(12)<<lastname<<setw(20)<<ops<<setw(20)<<job<<setw(7)<<salary<<endl;
}

Employee::~Employee(){
    cout << "   ~Employee() called" "   :" << this << endl;
};