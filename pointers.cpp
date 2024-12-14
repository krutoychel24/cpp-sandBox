#include <iostream>

using namespace std;

int main(){

int firstNum = 10;
int secondNum = 20;

cout << &firstNum << '\n';
cout << &secondNum << '\n';

int* firstNumPoiner {&firstNum};
int* secondNumPointer {&secondNum};

swap(firstNumPoiner, secondNumPointer);

cout << *firstNumPoiner << '\n';
cout << *secondNumPointer << '\n';

return 0;


}