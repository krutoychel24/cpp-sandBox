#include <iostream>

#include "LinkedList.hpp"
#include "Stack.hpp"
#include "Queue.hpp"

const int REGULAR = 1;
const int TRACE = 2;

void fire(Stack& ammo, int shots) {
    int shotsCounter = 0;

    if (shots <= 0)
    {
       return;
    }

    while (shotsCounter != shots && ammo.isEmpty() != true)
    {
        std::cout << "FIRE WITH BULLET TYPE: " << ammo.pop() << std::endl;
        shotsCounter++;
    }

    if (shotsCounter != shots)
    {
        std::cout << "AmmoBag is empty" << std::endl;
    }
}

int main()
{
    Stack ammo;
    
    ammo.push(REGULAR);
    ammo.push(REGULAR);
    ammo.push(REGULAR);
    ammo.push(TRACE);
    ammo.push(REGULAR);

    ammo.print();

    fire(ammo, 1);
    fire(ammo, 1);
    fire(ammo, 1);

    ammo.print();

    return 0;
}