#include <iostream>

#include "LinkedList.hpp"
#include "Stack.hpp"
#include "Queue.hpp"

const int REGULAR = 1;
const int TRACE = 2;

void fire(Queue& ammo, int shots) {
    int shotsCounter = 0;

    if (shots <= 0)
    {
       return;
    }

    while (shotsCounter != shots && ammo.isEmpty() != true)
    {
        std::cout << "FIRE WITH BULLET TYPE: " << ammo.dequeue() << std::endl;
        shotsCounter++;
    }

    if (shotsCounter != shots)
    {
        std::cout << "AmmoBag is empty" << std::endl;
    }
}

int main()
{
    Queue ammo;
    
    ammo.enqueue(REGULAR);
    ammo.enqueue(REGULAR);
    ammo.enqueue(REGULAR);
    ammo.enqueue(TRACE);
    ammo.enqueue(REGULAR);

    ammo.print();

    fire(ammo, 1);
    fire(ammo, 1);
    fire(ammo, 6);

    ammo.print();

    return 0;
}