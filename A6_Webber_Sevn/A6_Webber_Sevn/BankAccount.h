#pragma once
#include <iostream>

class BankAccount {
private:
    double* balance;
    double* interestRate;
    static int count;

public:
    BankAccount();
    BankAccount(double, double);
    virtual ~BankAccount();

    double get_balance() const;
    double get_interest_rate() const;
    void set_balance(double);
    void set_interest_rate(double);
    void print(std::ostream&);
    void deposit(double);
    void withdraw(double);
    static int get_count();
    virtual void update() = 0;
};
