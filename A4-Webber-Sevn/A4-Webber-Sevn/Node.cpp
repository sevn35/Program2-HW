#include "Node.h"

using namespace std;   
 
Node::Node(){
    cout << "Node() is called " << endl;
    emp = new Employee;
    next = nullptr; 
}

Node::Node(const string& x, Node* y){   
    cout << "   Node(const string& x, Node*) is called "<<"   :" << this << endl; //this displays address
    emp = new Employee(x);
    next = y; 
} 

Node::~Node(){
    cout << "~Node() called" "   :" << this << endl;
    delete emp;
}
