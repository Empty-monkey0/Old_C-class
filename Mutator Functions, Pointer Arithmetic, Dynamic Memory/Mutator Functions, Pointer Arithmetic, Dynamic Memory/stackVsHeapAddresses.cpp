//// stackVsHeapAddresses.cpp
// Example 3c
#include <iostream>
int main(){
    int stackVar = 10;
    int* heapVar = new int(20);
    std::cout << "Stack variable address: " << long(&stackVar) << "\n";
    std::cout << "Heap variable address:  " << long(heapVar) << "\n";
    std::cout << "Pointer itself (on stack): " << long(&heapVar) << "\n";
    delete heapVar;
    heapVar = nullptr;
}