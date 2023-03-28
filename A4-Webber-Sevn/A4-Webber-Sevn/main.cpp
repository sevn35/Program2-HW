/*
*   Course: CMSC2621 Prog II Lab
*	Assignment: A4
*	Description: This project is to practice a stack with a singly-linked list by modifying the program 
*       discussed in the class and your program for A2 where Employee was defined and used as a class.
*	Name: Sevn Webber
*	Date: 2/28/2023
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "Employee.h"
#include "DB.h"
#include "Node.h"

using namespace std;

int main(){

    fstream fin("employee.txt", ios::in); //reads txt file

    if(!fin.is_open()) { //fin.fail()
        cout << "file not opened\n";
        return 1;
    }

    string s; //Line of text to be added to employee class
    DB x; //SSL Object
    int size =0; //Current size of SSL

    while(getline(fin, s)){ //This Block sends each line of the file into DB
        x.insert(s);
        size++; 
    };	

    cout << endl << "After reading file" <<endl <<endl; //used for formatting
    x.print(cout); //Prints the list
  

    for(int i = 0; i<3; i++){ //This Block removes 3 Employees
        x.remove();
    }

    cout <<endl << "After Removing 3 Employees" <<endl <<endl;
    x.print(cout);

    for(int i =0; i< size; i++){ //Frees the memory
        x.~DB();
    };
}