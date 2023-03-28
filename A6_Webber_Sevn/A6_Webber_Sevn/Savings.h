#pragma once
#include "BankAccount.h"
#include <iostream>


class Savings : public BankAccount {
public:
    Savings();
    Savings(double, double);
    virtual ~Savings();
    void update() override;
};
