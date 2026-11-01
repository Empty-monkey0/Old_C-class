//// activityQ1.cpp
#include<iostream>
int main(){
    int x = 1;
    int* aX = &x;
    int* another = aX;
    *another += 1;
    std::cout << *aX;
}