#ifndef HUGEINT_H
#define HUGEINT_H

#include <iostream>

using std::ostream; //Not required but preffered over namespace std
using std::istream;
using std::string;

class HugeInt {
private:
    char*  number; //stored in heap
    int     size;
    void    computeSize(); //compute the size of the number and set the menber
    
public:
    HugeInt(long = 0); 
    HugeInt(const char*); 
    HugeInt(const HugeInt&); 
    ~HugeInt(); 

    HugeInt& operator=(const HugeInt&);
    HugeInt operator+(const HugeInt&);
    HugeInt operator-(const HugeInt&);
    HugeInt operator*(const HugeInt&); 
    HugeInt operator/(const HugeInt&);
    HugeInt operator%(const HugeInt&);

    HugeInt& operator++();
    HugeInt operator++(int);
    bool    operator<=(const HugeInt&);
    short&  operator[](int);
    operator long double();
    
    friend ostream& operator<<(ostream&, const HugeInt &);
    friend istream& operator>>(istream&, HugeInt&);
    
};

#endif
