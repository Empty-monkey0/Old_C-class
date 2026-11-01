//// memoryLeak.cpp
// Example 4b
#include <iostream>
int main(){
    int* ptr = new int(5);
    ptr = new int(10);
    
    std::cout << *ptr << "\n";
    delete ptr;
    ptr = nullptr;
}