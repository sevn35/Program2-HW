#include "Savings.h"
using namespace std;

Savings::Savings() : BankAccount() {}

Savings::Savings(double bal, double ir) : BankAccount(bal, ir) {
    cout << "Savings(double bal, double ir) called : " << this<<endl;
}

Savings::~Savings(){
    cout<< "~Savings()called : "<<this<<endl;
}

void Savings::update() {
    this->set_balance(this->get_balance()*(this->get_interest_rate()+1)); //balance = balance * (interest+1)
}
