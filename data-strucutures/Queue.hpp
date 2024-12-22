#pragma once
#ifndef QUEUE
#define QUEUE

class Queue {
    int peek(); // return front element
    void enqueue(int val); // add to the queue
    int dequeue(); // remove from the queue
};
#endif