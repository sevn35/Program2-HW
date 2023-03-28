#include "DB.h"
#include "Node.h"
#include <iomanip>


DB::DB(){
    this->top = nullptr; //this->: the address of an object of DB
    this->count =0;
    cout<< "DB:DB() called" << endl;
} 

DB::~DB(){ //destroy the entire sll if the top is not nullptr
    while(top != nullptr){
        Node* temp = top; 
        top = top->next;
        delete temp;
    }
}

void DB::insert(const string& d){
    cout << "DB:insert() called" <<endl;
    Node* temp = new Node(d, nullptr); //creates a pointer to new node
    temp->next = this->top; //Changes next in node to value of next node
    count++;
    top = temp; //top becomes the address of new node
}

void DB::remove(){ //removes top node then resets the address of top
    if(top != nullptr){ 
        Node* temp = top;
        top = top->next;
        delete temp;
        count--;
    }
    
}

void DB::print(ostream& out){
    Node* temp1 = top; 
    cout << "---------------------------------------------------------------------------------------" <<endl;
    out <<left<<setw(5)<<"Code"<<setw(12)<<"SSN"<<setw(12)<<"first name"<<setw(12)<<"last name"<<setw(20)<<"Dept"<<setw(20)<<"Role"<<setw(7)<<"Salary"<<endl;
    cout << "---------------------------------------------------------------------------------------" <<endl;
    while(temp1 != nullptr){
        temp1->emp->display(out); // pulls function from employee to display data
        temp1 = temp1->next;
    }
}