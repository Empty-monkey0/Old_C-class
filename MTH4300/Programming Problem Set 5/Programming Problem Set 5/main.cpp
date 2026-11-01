/******************************************************************************
 main.cpp
******************************************************************************
 Name:Tauseen Ahmed
******************************************************************************
 AI conversation links (Step 2 and/or Step 3):
https://chatgpt.com/share/69e29961-84dc-83e8-bf01-cb5d5aa3aefc
https://chatgpt.com/share/69e2a721-c254-83e8-9a84-f35f4f79a014

Questions section
 1. Without a copy constructor, the compiler does a shallow copy and it copies the pointer value, not the array it points to.
Both arr and copy1 would share the same heap memory and when one goes out of scope, its destructor
calls delete[] on that memory. When the second goes out of scope, its destructor calls delete[] on the same freed memory
causing a crash.

 2. the expression a = b =arr is evaluated as a = (b = arr). The inner call mus return a reference to be so the
 outer assignment can use it as the right-hand opereand. If operator= returned void, (b = arr) would produce void
 and a = void would not compile.

 3. Without the elf-assignment check, operator= would first delete[] data but since this and &other are the same object, other.data is now a dangling pointer
 to freed memory. The next step allocates new memory and tries to copy from other.data which reading freed
 memory is undefined behavior. The array would crash or contain garbage.


******************************************************************************
 Overall notes (not to replace inline comments):


*/

// To compile and run locally:
//   g++ DynamicArray.cpp main.cpp -o main
//   ./main

#include<iostream>
#include "DynamicArray.h"


// ============================================================
// TESTER CODE — uncomment sections as you implement each part.
// For Part (c), delete this tester code and write your own main()
// following the instructions in the assignment.
// ============================================================

int main(){
    int n;
    std::cin >> n;
    DynamicArray arr;
    for(int i =0; i < n; i++){
        int val;
        std::cin >> val;
        arr.push_back(val);

    }
    arr.print();


    //Copy constructor
    DynamicArray copy1(arr);
    copy1.set(0, -999);

    std::cout << "After modifying copy1:" << std::endl;
    std::cout << "arr: ";
    arr.print();
    std::cout << "copy1: ";
    copy1.print();

    // Chained assingment section
    DynamicArray a;
    DynamicArray b;
    a = b = arr;

    std::cout << "After chained assignment:" << std::endl;
    std::cout << "arr: ";
    arr.print();
    std::cout << "a: ";
    a.print();
    std::cout << "b: ";
    b.print();

    a.set(0,0);
    b.set(0,1);

    std::cout << "After modifying a and b:" << std::endl;
    std::cout << "arr: ";
    arr.print();
    std::cout << "a: ";
    a.print();
    std::cout << "b: ";
    b.print();

    // Self assignment
    arr = arr;
    std::cout << "After self-assignment:" << std::endl;
    std::cout << "arr: ";
    arr.print();

    return 0;

}




/*
int main()
{
    // --- Part (a): Core DynamicArray class ---

    DynamicArray d1;
    std::cout << "Size: " << d1.getSize() << std::endl;       // Expected: 0
    std::cout << "Capacity: " << d1.getCapacity() << std::endl; // Expected: 10

    DynamicArray d2(3);
    std::cout << "Size: " << d2.getSize() << std::endl;       // Expected: 0
    std::cout << "Capacity: " << d2.getCapacity() << std::endl; // Expected: 3

    d2.push_back(10);
    d2.push_back(20);
    d2.push_back(30);
    std::cout << "Size: " << d2.getSize() << std::endl;       // Expected: 3
    std::cout << "Capacity: " << d2.getCapacity() << std::endl; // Expected: 3
    d2.print();                                      // Expected: [10, 20, 30]

    d2.push_back(40);
    std::cout << "Size: " << d2.getSize() << std::endl;       // Expected: 4
    std::cout << "Capacity: " << d2.getCapacity() << std::endl; // Expected: 6
    d2.print();                                      // Expected: [10, 20, 30, 40]

    std::cout << d2.get(0) << std::endl;  // Expected: 10
    std::cout << d2.get(3) << std::endl;  // Expected: 40
    d2.get(10);                 // Expected: Error: index out of bounds
    d2.get(-1);                 // Expected: Error: index out of bounds

    d2.set(0, 99);
    d2.print();                 // Expected: [99, 20, 30, 40]
    d2.set(10, 5);              // Expected: Error: index out of bounds

    DynamicArray d3;
    d3.print();                 // Expected: []

    return 0;
}
*/
