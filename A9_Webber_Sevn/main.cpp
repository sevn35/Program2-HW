#include <cstdlib>
#include <iostream>
#include "Heap.h"

using namespace std;


int main() {
    const int SIZE = 11;
    int numbers[] = {5,10,4,3,1,15,11,12,20,19,2};

    cout << "Original Array:" <<endl;
    for(int i=0;i<SIZE;i++)
        cout << numbers[i] << "  ";
    
    cout << endl << "Build a min heap..." << endl;
    Heap h;
    //make a for loop to test insertion
    for(int i=0;i<SIZE;i++){
        h.insert(numbers[i]);
    }

    h.Display();
    

    cout<< "Testing removeMin()..." << endl;  
    while (h.size()!=0) {
        cout << h.removeMin() << "  ";
    }
    cout<<endl;

    try
    {
        cout << "Testing Top()..." << endl;
        if (h.size() == 0)
        {
            throw Heap::heapEmptyException();
        }
        cout << h.top() << endl;
    }
    catch (...)
    {
        cout << "Heap Empty Exception Caught!" << endl;
    }


    try{
        cout<< "Testing removeMin()..." << endl;
        if(h.size()==0){
            throw Heap::heapEmptyException();;
        }
        h.removeMin();
    }catch(...){
        cout << "Heap Empty Exception Caught!" << endl;
    }

    return 0;
}

