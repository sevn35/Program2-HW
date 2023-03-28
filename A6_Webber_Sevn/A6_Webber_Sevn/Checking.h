#pragma once
#include "BankAccount.h"

class Checking : public BankAccount {
public:
    Checking();
    Checking(double, double);
    virtual ~Checking();
    void update() override;

};
