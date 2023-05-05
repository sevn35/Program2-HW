
#include <iostream>
#include "Heap.h"

using namespace std;

Heap::Heap()
{
    int not_used = -10;
    elements.push_back(not_used);
}
/*
Heap::~Heap() {
}
*/

void Heap::Display() const
{
    for (int i = 1; i < size() + 1; i++)
    {
        cout << elements[i] << "  ";
    }
    cout << endl;
}
void Heap::insert(int key)
{

    elements.push_back(key);

    // fix the heap
    percolateUp();
}

void Heap::percolateUp()
{

    int cur_idx = elements.size() - 1;
    if (cur_idx == 1)
        return;

    // demote parents that are larger than the new element
    bool more = true;
    do
    {
        int parent_key = elements[cur_idx / 2];
        int new_key = elements[cur_idx];
        if (cur_idx != 1)
        { // curIdx: not yet reach root
            if (parent_key > new_key)
            {
                elements[cur_idx] = parent_key;
                elements[cur_idx / 2] = new_key;
            }
            cur_idx--;
        }
        else
        {
            more = false;
        }
    } while (more);
}

int Heap::top() const
{
        return elements[1];
}

int Heap::size() const
{
    return elements.size() - 1; // note: elements[0] is not used
}

int Heap::removeMin()
{
    // remove the last element
    int min = elements[1];
    int cur_idx = elements.size() - 1;
    int last_key = elements[cur_idx];
    elements.pop_back();

    if (cur_idx != 1)
    {
        elements[1] = last_key;
        percolateDown();
    }
    return min;

}

void Heap::percolateDown()
{

    int last_idx = elements.size() - 1;
    if (last_idx == 1)
        return;

    // promote children of removed rootKey while they are smaller than last
    int cur_idx = 1;
    bool more = true;
    while (more)
    {
        int leftC_idx = cur_idx * 2;
        int parent_key = elements[cur_idx];
        if (leftC_idx <= last_idx)
        {
            if (elements[leftC_idx] < parent_key)
            {
                int new_key = elements[leftC_idx];
                elements[cur_idx] = new_key;
                elements[leftC_idx] = parent_key;
                parent_key = elements[cur_idx];

            }
            if (elements[leftC_idx+1] < parent_key && (leftC_idx+1) <= last_idx)
            {
                int new_key = elements[leftC_idx+1];
                elements[cur_idx] = new_key;
                elements[leftC_idx+1] = parent_key;
            }
            cur_idx++;
        }
        else
        {
            // no children
            more = false;
        }
    }

    // store rootKey element in vacant slot
}
