//// swapWrong1.cpp
// Example 1c - what's wrong with this swap?
#include <iostream>
void swap(int* aX, int* aY){
    int* temp = aX;
    *aX = *aY;
    *aY = *temp;
}
int main(){
    int x = 7;
    int y = 17;
    swap(&x, &y);
    std::cout << x << " " << y << "\n"; // should print 17 7
}