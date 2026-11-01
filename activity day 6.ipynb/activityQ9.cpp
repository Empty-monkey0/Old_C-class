//// activityQ9.cpp
#include<iostream>
int main(){
    int x = 1;
    int* aX = &x;
    int* another = aX;
    *another += 1;
    std::cout << *aX;

    // which one(s) make sense below?
    std::cout << *(&x) << "\n";
    std::cout << &(*x) << "\n";
    std::cout << &(*aX) << "\n";
}