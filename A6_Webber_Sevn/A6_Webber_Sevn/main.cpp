#include <iostream>
#include "Checking.h"
#include "Savings.h"
#include <typeinfo>
using namespace std;

int main() {
    int size=6;
    // Create bank accounts
    BankAccount* accounts[size]={new Savings(500.50, 0.03), new Savings(700.70, 0.03) ,new Savings(900.90, 0.03),
        new Checking(200.10, 0.015),new Checking(400.30, 0.015), new Checking(600.60, 0.015)};

    for(int i=0;i<5;i++){ //Loop for all 5 years
        for(int j=0;j<6;j++){ //Loop for all 6 elements of accounts
            for(int k=0;k<3;k++){ //Loop for 3 deposits
                accounts[j]->deposit(300);
            }
            accounts[j]->withdraw(150.50);
            accounts[j]->update(); //calculates interest
        }
    }

    cout <<endl<<endl<<endl;
    cout << "At the end of the 5th year:"<<endl;
    cout << "Number of accounts: " << size<<endl;
    for(int i=0;i<size;i++){
        if(i<3)
            cout <<"Savings Account #"<< (i+1) << " : " << accounts[i]->get_balance()<<endl;
        else
            cout <<"Checking Account #"<< (i+1) << " : " << accounts[i]->get_balance()<<endl;
    }
    cout <<endl<<endl<<endl;
    
    for(int i=0;i<size;i++)
        delete accounts[i];



}
