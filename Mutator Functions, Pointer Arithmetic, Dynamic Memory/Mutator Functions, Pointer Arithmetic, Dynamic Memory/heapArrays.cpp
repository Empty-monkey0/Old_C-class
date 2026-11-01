//// heapArrays.cpp
// Example 3f
#include <iostream>
int main(){
    int* arr = new int[5];  // allocate an array of 5 ints on the heap
    for (int i = 0; i < 5; i++){
        arr[i] = i * 2;
        *(arr + i) = i * 2; //equivalent to previous line
        std::cout << "arr[" << i << "] = " << arr[i]
                  << "  address: " << long(&arr[i]) << "\n";
    }
    delete[] arr;  // free the array — note the []
    arr = nullptr;
}