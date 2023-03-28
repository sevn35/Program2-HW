#include "BankAccount.h"
using namespace std;

int BankAccount::count = 0;//

BankAccount::BankAccount() : BankAccount(0.0, 0.0) {}

BankAccount::BankAccount(double bal, double ir) {
    cout << "BankAccount(double bal, double ir) called : " << this <<endl;
    balance = new double;
    interestRate = new double;
    *balance = bal;
    *interestRate = ir;
    count++;
}

BankAccount::~BankAccount() {
    cout << "~BankAccount() called : " << this <<endl;
    delete balance;
    delete interestRate;
    count--;
}

double BankAccount::get_balance() const {
    return *balance;
}

double BankAccount::get_interest_rate() const {
    return *interestRate;
}

void BankAccount::set_balance(double bal) {
    *balance = bal;
}

void BankAccount::set_interest_rate(double ir) {
    *interestRate = ir;
}

void BankAccount::print(std::ostream& os) {
    os << "Balance: " << *balance << ", Interest Rate: " << *interestRate;
}

void BankAccount::deposit(double amount) {
    *balance += amount;
}

void BankAccount::withdraw(double amount) {
    if (*balance >= amount) {
        *balance -= amount;
    }
    else {
        std::cout << "Invalid withdrawal" << std::endl;
    }
}

int BankAccount::get_count() {
    return count;
}
