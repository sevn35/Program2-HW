/*
*   Course: CMSC2621 Prog II Lab
*	Assignment: A2
*	Description: This project is to review file handling, struct type, array, and separate compilation 
*   with the make utility
*	Name: Sevn Webber
*	Date: 2/8/2023
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "employee.h"

using namespace std;

//function prototype
void print_dept_info(employee**, int);


//This Program takes info from txt file and organizes it
int main(){

  //opens employee.txt
  fstream fin("employee.txt", ios::in); 

  //Fail safe incase the file does not exist
  if(!fin.is_open()) { //fin.fail()
    cout << "file not opened\n";
    return 1;
  }			

  //creates pointer array of employee type
  const int size = 30;
  employee * s[size];

  //assins values to each element of s using the employee type  
  int i = 0;
  while(i<size) {
    s[i] = new employee;
    fin >> s[i]->ec >> s[i]->ssn >> s[i]->firstname >> s[i]->lastname >> s[i]->ops >> s[i]->job >> s[i]->salary;
    i++; 
  };

  //Closes the file handaler
  fin.close();

  //this function prints the information, More info in function body
  print_dept_info(s, size);

  //Dealocates Memory
  while(i>=0){
    delete s[i];
    i--;
  };

  return 0;
};

//This function takes in the employee pointer array and uses it to display and organize info
void print_dept_info(employee** x, int y){

  //this block creates new array of the DeptInfo type 
  string deps[] = {"DevOps", "SecOps", "AccountFinance", "Sales", "Administration"};
  DeptInfo a[5];
  int sze = 0; //size of all employees
  int total = 0; //Total salary for all employees

  //Gives a defualt values for Dev teams using deps array
  for(int i =0; i<5; i++){
    a[i].Department = deps[i];
  };

  //Goes through both arrays and if department names match individual values are copied over
  for(int i =0; i<5; i++){//sets up DepartInfo array
    for(int j =0; j<y; j++){//Compares a and "x"
      if(a[i].Department == x[j]->ops){
        a[i].size++;
        a[i].totalSalary += x[j]->salary;
      }
    }
    sze += a[i].size; //used for summary
    total += a[i].totalSalary; //used for summary
  };

  //Information Display
  cout << "------------------------------------------" << endl;
  cout << "Department             Size   Avg. Salary"  << endl;
  for(int i =0; i<5; i++){
    cout << left << setw(25) << a[i].Department << setw(8) << a[i].size << setprecision(8) << a[i].totalSalary/a[i].size << endl;
  };
  cout << "------------------------------------------" << endl;
  cout << left << setw(25) << "Summary" << setw(8) << sze << total/sze << endl;
};