#include "Checking.h"
using namespace std;

Checking::Checking() : BankAccount() {}

Checking::Checking(double bal, double ir) : BankAccount(bal, ir) {
    cout << "Checking(double bal, double ir) called : " << this <<endl;
}

Checking::~Checking(){
    cout << "~Checking() called : " << this <<endl;
}

void Checking::update() {
    if (this->get_balance() > 1000) {
        this->set_balance(this->get_balance()*(this->get_interest_rate()+1)); //balance = balance * (interest+1)
    }
}
