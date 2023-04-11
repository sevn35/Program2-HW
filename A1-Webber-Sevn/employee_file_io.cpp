/*
*   Course: CMSC2621 Prog II Lab
*	Assignment: A1: Warm-up 
*	Description: This project is to review file handling, struct type, array, and separate compilation 
*   with the make utility
*	Name: Sevn Webber
*	Date: 1/30/2023
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "employee.h"

using namespace std;

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

int main(){

    fstream fin("employee.txt", ios::in); 

    if(!fin.is_open()) { //fin.fail()
        cout << "file not opened\n";
        return 1;
    }			

    const int size = 50;
    employee s[size];
    
    int i = 0;
    while(fin >> s[i].ec >> s[i].ssn >> s[i].firstname >> s[i].lastname >> s[i].ops >> s[i].job >> s[i].salary) {
        i++;
    };

    fin.close();


    /*
    cout << "The size of employees is " << i << endl << endl;

    for(int j =0; j<i; j++){
    cout << left << setw(2) << s[j].ec << setw(12) << s[j].ssn << setw(12) << s[j].firstname << setw(12) << s[j].lastname << setw(20)<< s[j].ops << setw(20) << s[j].job << setw(7) << s[j].salary << endl;
    }

    */

  while(true){
    int input =0;
    string input2;
    
    cout << "---------  Search Menu  --------" << endl;
    cout << "1. Search by Social Security Number" << endl;
    cout << "2. View only SpecOps team" << endl;
    cout << "3. View only DevOps Developers" << endl;
    cout << "4. Exit" << endl;
    cout << "--------------------------------" << endl << endl;
    cout << "Enter a number to select what you want: ";
    cin >> input;

    int count = 0;
    switch (input) {
      case 1:
        cout << "Enter a SSN: ";
        cin >> input2;
        for(int j =0; j<i; j++){
          if(s[j].ssn == input2){
            cout << endl << left << setw(2) << s[j].ec << setw(12) << s[j].ssn << setw(12) << s[j].firstname << setw(12) << s[j].lastname << setw(20)<< s[j].ops << setw(20) << s[j].job << setw(7) << s[j].salary << endl <<endl;}
        }
        break;

      case 2:
        for(int j =0; j<i; j++){
          if(s[j].ops== "SecOps"){
            count++;
            cout << left << setw(2) << s[j].ec << setw(12) << s[j].ssn << setw(12) << s[j].firstname << setw(12) << s[j].lastname << setw(20)<< s[j].ops << setw(20) << s[j].job << setw(7) << s[j].salary << endl;}
        }
        cout << endl << "Number of matched employees: " << count << endl;
        count = 0;
        break;

      case 3:
        for(int j =0; j<i; j++){
          if((s[j].ops== "DevOps")&&(s[j].job== "Developer")){
            count++;
            cout << left << setw(2) << s[j].ec << setw(12) << s[j].ssn << setw(12) << s[j].firstname << setw(12) << s[j].lastname << setw(20)<< s[j].ops << setw(20) << s[j].job << setw(7) << s[j].salary << endl;}
        }
        cout << endl << "Number of matched employees: " << count << endl;
        count = 0;
        break;

      case 4:
        return 0;
    };
  } 

    return 0;
}