#include <cctype> //isdigit()
#include <cstring> //strlen
#include "HugeInt.h"
using std::endl;
using std::cout;

HugeInt::HugeInt(long value) 
{
    cout <<"HugeInt(long) called" << endl; 
    number = new char[30];

    long expo =10; //expo is a long to match the amount of digits of value
    for(int j=0;j<30;j++){
        number[29-j] = (value%expo-(value%(expo/10)))/(expo/10); //expo is divided by 10 to give prior exponent
        expo *= 10;  //expo goes up by a power of 10 each time for each digit
    }                
    computeSize();
}

void HugeInt::computeSize()
{
    int x = 30;
    for(int i=0; i<29; i++){    //iterates through the array until it detects a non-zero number
        if((this->number[i])==0)
            x--;                //if i is a 0 the total count goes down
        else
            break;              //the first non zero ends the loop returning size
    }
    this->size = x;
}

HugeInt::HugeInt(const char* string)
{
    cout <<"HugeInt(const char*) called" << endl;
    number = new char[30];
    int sizeRemainder = 30-strlen(string);
    int size = 30;
    for(int i = 0; i < 30; i++){ //sets all digits to zero
        this->number[i] = 0;
    }

    for(int i=29; i>=0; i--){  
        if(i-sizeRemainder<0)                           //if(stringSize) breaks loop when string runs out of characters
            break;                                      //sets the last digit of number to the last digit of string
        this->number[i] = (string[i-sizeRemainder]-48); 
    }                                                   // -48 sets the digits ascii to 0-9 for math later
    computeSize();
}

HugeInt::HugeInt(const HugeInt& copy) 
{
    cout <<"HugeInt(const HugeInt&) called" << endl;
    number = new char[30];

    for(int i = 0; i < 30; i++){ 
        this->number[i] = copy.number[i];
    }
    this->size = copy.size;
    computeSize();
}
          
HugeInt::~HugeInt()
{
    cout <<"~HugeInt() called" << endl;
    delete[] number;

}

HugeInt& HugeInt::operator=(const HugeInt& right)
{
    cout <<"operator=(const HugeInt&)  called" << endl;
    HugeInt local(right);

    char* temp = local.number;
    local.number = this->number;
    this->number=temp;

    int temp2 = local.size;
    local.size = this->size;
    this->size = temp2;

    return *this;

}

HugeInt HugeInt::operator+(const HugeInt& right)
{
    cout << "operator+(const HugeInt&)" << endl;
    HugeInt temp;
    int remainder =0; 
    for(int i=29; i>-1; i--){
        if((this->number[i]+right.number[i]+remainder)<10){ //if the problem does not go out of bounds
            temp.number[i] = this->number[i]+right.number[i]+remainder;
            remainder = 0;
        }
        else if((this->number[i]+right.number[i]+remainder)>9){ //if problem goes out of bounds
            temp.number[i] = (this->number[i]+right.number[i]+remainder)-10;
            remainder = 1;
        }    
    }
    temp.computeSize();
    return temp; 
}

HugeInt HugeInt::operator-(const HugeInt& right)
{
    cout << "operator-(const HugeInt&)" << endl;
    HugeInt temp;
    int remainder =0; 
    for(int i=29; i>-1; i--){
        if(((this->number[i]-right.number[i])-remainder)>-1){ //if the problem does not go out of bounds
            temp.number[i] = (this->number[i]-right.number[i])-remainder;
            remainder = 0;
        }
        else if(((this->number[i]-right.number[i])-remainder)<0){ //if problem goes out of bounds
            temp.number[i] = (this->number[i]+right.number[i]+remainder)+10;
            remainder = 1;
        }    
    }
    temp.computeSize();
    return temp; 
}

HugeInt HugeInt::operator*(const HugeInt& right)  
{                                                
    cout << "operator*(const HugeInt&)" << endl;
    HugeInt temp;
    int remainder =0;
    int expo = 0;
    for(int j =29;j>-1;j--){
        for(int i=29; i>-1; i--){ 
            if((this->number[i]*right.number[j])+temp.number[i-expo]+remainder<10){ //increment does not go out of bounds
                temp.number[i-expo] += (this->number[i]*right.number[j])+remainder;
                remainder = 0;
            }
            else if((this->number[i]*right.number[j])+remainder+temp.number[i-expo]>9){ //increment does go out of bounds
                //[i-expo] simulates the integer at j going up by a tens place
                temp.number[i-expo] += ((this->number[i]*right.number[j])+remainder)%10;
                remainder = ((this->number[i]*right.number[j])+remainder)/10;
            }
        }
        expo++;
    }
    temp.computeSize();
    return temp;
}

HugeInt HugeInt::operator/(const HugeInt& right) 
{
    cout << "operator/(const HugeInt&)" << endl;
    //This block converts the divisor into a long similar to my long double code
    long divisor = 0;
    long  expo =1;
    for(int i =29; i>-1; i--){
        divisor += right.number[i]*expo; //adds digit at i * the value of the tens place its at
        expo *= 10; // expo goes up by a power of 10 for next spot
    }

    HugeInt temp; //return value
    int pos = 0; //divisor position
    int pos2 = 0; //used for HugeInt return
    long remainder = this->number[pos]; // used to remember remainder of division

    while(pos<30){ //TODO This should be 29 but that breaks it for some reason
        if(remainder >= divisor){ //Quitient is added to top and remainder is recalulated
            temp.number[pos2] = remainder/divisor;
            pos++; // position of dividend
            pos2++; //pos of temp
            remainder = ((remainder%divisor)*10) + this->number[pos];//brings down next element
        }
        else if(remainder < divisor){//If remainder is less then divisor,quotient is zero and next element is brought down
            temp.number[pos2] = 0; //could be replaced with =remainder/divisor
            pos++;
            pos2++;
            remainder = (remainder*10) + this->number[pos]; //brings down next element
        }
    }
    temp.computeSize();
    return temp;
}

HugeInt HugeInt::operator%(const HugeInt& right)
{
    
    cout << "operator%(const HugeInt&)" << endl;
    long divisor = 0;
    long  expo =1;
    for(int i =29; i>-1; i--){
        divisor += right.number[i]*expo; //adds digit at i * the value of the tens place its at
        expo *= 10; // expo goes up by a power of 10 for next spot
    }

    int pos = 0; //divisor position used for while statement
    long remainder = this->number[pos]; // used to remember remainder of division

    while(pos<30){ //TODO This should be 29 but that breaks it for some reason
        if(remainder >= divisor){ //Same code as divison without keeping tract of qoutient
            pos++; // position of dividend
            remainder = ((remainder%divisor)*10) + this->number[pos];
        }
        else if(remainder < divisor){//If remainder is less then divisor, the next element is brought down
            pos++;
            remainder = (remainder*10) + this->number[pos];
        }
    }
    HugeInt temp(remainder/10); //TODO get rid of the /10 when i figure out pos<29
    temp.computeSize();
    return temp;
    
}

HugeInt& HugeInt::operator++()
{
    cout << "operator++()" << endl;
    int remainder =0; 
    for(int i=29; i>-1; i--){ //Very similar code to addition operator
        if(number[i]+1+remainder<10){ //increment does not go out of bounds
            number[i] +=1;
            break;
        }
        else if(number[i]+1+remainder>9){ //increment goes out of bounds
            number[i] = (number[i]+1+remainder)-10;
            remainder = 1;
        }
    }
    return *this;
}

HugeInt HugeInt::operator++(int)
{
    cout << "operator++(int)" << endl;
    HugeInt temp = *this;
    operator++();//reuse code from prior operator to increment
    return temp; //returns HugeInt before increment
}

HugeInt::operator long double()
{
    cout << "operator long double()" << endl;
    long double temp = 0;
    long double expo =1;
    for(int i =29; i>-1; i--){
        temp += this->number[i]*expo; //adds digit at i * the value of the tens place its at
        expo *= 10; // expo goes up by a power of 10 for next spot
    }
    return temp;
}

bool HugeInt::operator<=(const HugeInt& right) {
    cout << "operator<=(const HugeInt& )" << endl;
    for(int i=0; i<30; i++){
        if(this->number[i]!=right.number[i])
            if(this->number>right.number)
                return false; //Left is greater than right in the first non equal index
            else if(this->number<right.number)
                return true; //Left is less than right in the first non equal index
    }
    return true; //Both HugeInts are equal
}

short& HugeInt::operator[](int index){
    cout << "operator[](int)" << endl;
    return (short&)number[index]; 
};

ostream& operator<<(ostream& out, const HugeInt& n)
{
    cout << "operator<<(ostream&, const HugeInt& )" << endl;
    out << "Value : ";
    for(int i=30-n.size; i<30;i++) //only displays numbers for current size
        out << char(n.number[i]+48);
    out << " || size = " << n.size << endl;
    return out;
}   

istream& operator>>(istream& in, HugeInt& n)
{
    cout << "operator>>(istream&, HugeInt& )" << endl;
    in >> n.number; 
    int size=0; //computesize() does not work here
    for(int i=0; i<30; i++){ // gets size by checking if current char is digit
        if(isdigit(n.number[i])){
            size++;
            n.number[i]-=48; // sets number[i] to ascii digit
        }
    }
    for(int j=0; j<30-size; j++){//shifts the array over
        for(int i=28;i>-1;i--)
            n.number[i+1] = (n.number[i]);
        n.number[0]=0; //Needed to reset digits of array
    }
    n.size = size; 
    return in;
}
