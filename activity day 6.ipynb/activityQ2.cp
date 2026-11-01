//// activityQ2.cp
#include<iostream>
int main(){
    int a = 1;
    int* b = &a;
    a += 1;
    *b += 1;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << *b << std::endl;
}