//// danglingOverwrite.cpp
// Example 3d
#include <iostream>
int* createValue(){
    int x = 3;
    return &x;
}
void anotherFunction(){
    int y = 42;
}
int main(){
    int* ptr = createValue();
    anotherFunction();
    std::cout << *ptr << "\n";  // what will this print?
}