//// ptrArithPractice.cpp
// Example 2f
#include <iostream>
int main(){
    int myArray[] = {5, 10, 15, 20, 25};
    int* myPtr = myArray;
    int* myPtr2 = myPtr + 3;
    std::cout << *myPtr2 << "\n";
    std::cout << *(myPtr2 - 1) << "\n";
    std::cout << myPtr2[-1] << "\n";
}