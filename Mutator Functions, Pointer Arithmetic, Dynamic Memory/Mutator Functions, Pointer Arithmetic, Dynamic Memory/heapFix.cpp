//// heapFix.cpp
// Example 3e
#include <iostream>
int* createValue(){
    int * ptrX = new int(3);
    return ptrX;
}
void anotherFunction(){
    int y = 42;
}
int main(){
    int* ptr = createValue();
    anotherFunction();
    std::cout << *ptr << "\n"; 
    delete ptr;  // why this line?
    ptr = nullptr;
}