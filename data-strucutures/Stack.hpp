#pragma once

#ifndef STACK
#define STACK
#include "LinkedList.hpp"

class Stack
{
    public:
        int pop() 
        {
            int i = list.tailElement();
            list.removeLast();
            return i;
        }
        
        int top()
        {
            return list.tailElement();
        }

        void push(int val)
        {
            list.insert(val);
        }

        void print() {
            list.printList();
            std::cout << std::endl << "There are " << list.getSize() << " bullets left." << std::endl;
        }

        bool isEmpty() 
        {
            return 0 == list.getSize();
        }

    private:
        LinkedList list;
};
#endif