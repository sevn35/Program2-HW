#ifndef DB_H
#define DB_H
#include "Node.h"

class DB {	//DB’s behavior is LIFO like a stack.
private:
    Node* top; //this is the pointer to the first node in the singly linked list
    int   count; //the length of the SLL in terms of the number of data items stored
public:
    DB();
    ~DB();
    void  insert(const string&); 
    void  remove();                
    void  print(ostream&);       
};
#endif
