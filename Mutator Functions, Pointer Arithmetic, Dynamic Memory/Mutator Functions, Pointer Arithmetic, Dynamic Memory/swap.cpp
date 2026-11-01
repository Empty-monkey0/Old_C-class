//// swap.cpp
// Example 1b - write the swap function
#include <iostream>

// write the swap function here
void swap(int* aX, int* aY){
    int temp = *aX;
    *aX = *aY;
    *aY = temp;
    
}

int main(){
    int x = 7;
    int y = 17;
    swap(&x, &y);
    std::cout << x << " " << y << "\n"; // should print 17 7
}