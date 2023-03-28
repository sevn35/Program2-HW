#ifndef Executive_H
#define EXECUTIVE_H

#include "Manager.h"

class Executive : public Manager{
public:
    Executive();
    Executive(string, string, string, float, string);
    ~Executive();
    void print(ostream&);
};
#endif