#pragma once

#ifndef QUEUE
#define QUEUE
#include "LinkedList.hpp"

class Queue {
    private:
    LinkedList list;

    public:
    int peek()
    {
        int frontElem = list.headElement();
        return frontElem;
    } 

    void enqueue(int val)
    {
        list.insert(val);
    } 
    int dequeue()
    {
        peek();
        list.removeFirst();
        return peek();
    }

        void print() 
        {
            list.printList();
            std::cout << std::endl << "There are " << list.getSize() << " bullets left." << std::endl;
        }

        bool isEmpty() 
        {
            return 0 == list.getSize();
        }
};
#endif