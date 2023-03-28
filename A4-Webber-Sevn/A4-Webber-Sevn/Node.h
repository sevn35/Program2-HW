#ifndef NODE_H
#define NODE_H
#include "Employee.h"

using namespace std;

class DB;	//Forward declaration or reference

class Node {
private:
    Employee* emp;  //pointer to an object of Employee class
    Node*      next;     //pointer to an object of Node class
public:
    Node();
    Node(const string&, Node*); //Node* is to create a link to another Node
    ~Node();
    friend class DB; //make the DB class a friend of Node
		
};
#endif
