//// mutators.cpp
// Example 1a
#include <iostream>
void addTwoToXAndThreeToY(int* aX, int* aY){
    *aX = *aX + 2;
    *aY = *aY + 3;
}
int main(){
    int x, y;
    x = 7; y = 17;
    std::cout << "old x = " << x << "\n";
    std::cout << "old y = " << y << "\n";
    addTwoToXAndThreeToY(&x, &y);
    std::cout << "new x = " << x << "\n";
    std::cout << "new y = " << y << "\n";
}