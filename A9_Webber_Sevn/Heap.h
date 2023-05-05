
/* This file Implements of a Min Heap for 'int' type elements
   by using vector
*/
#ifndef HEAP_H
#define	HEAP_H

#include <vector>
using namespace std;

class Heap {
private:
    vector<int> elements; //empty vector
    
public:
    Heap();
    //~Heap(); not needed since nothing is created in the heap
    void   insert(int e); // adds a new element to this heap
    int top() const;	     // gets the min element in the heap without removal
    int removeMin();      // removes the min element from the heap
    int  size() const;     // returns the # of elements in the heap
    void Display() const;
    class heapEmptyException{};

    
private: // utility functions called by insert and removeMin

    void   percolateDown();
    void   percolateUp();

};

#endif	
