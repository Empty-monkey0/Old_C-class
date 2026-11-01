/******************************************************************************
 DynamicArray.cpp
******************************************************************************
 Name: Tauseen Ahmed
******************************************************************************
 AI conversation links (Step 2 and/or Step 3):
I will place all Ai and questions on 5c

******************************************************************************
 Overall notes (not to replace inline comments):


*/

#include "DynamicArray.h" // write the class declaration in the header file; implement the methods here
// No global variables

// this file should not contain a main function, only the method implementations

// Note: default parameter values go in the .h file only, not here.
// Reminder: when implementing methods here, use ClassName::methodName syntax.
// The class name goes after the return type, e.g.:
//   void DynamicArray::push_back(int val) { ... }

// constructor
DynamicArray::DynamicArray(int cap){
    capacity = cap;
    size = 0;
    data = new int[capacity];

}
//Destructor
DynamicArray::~DynamicArray(){
    delete[] data;
}

// push_back
void DynamicArray::push_back(int val){
    if (size == capacity){

        capacity = capacity * 2;
        int* newData = new int[capacity];
        for( int i =0; i < size; i++){
            newData[i] = data[i];

        }
        delete[] data;
        data = newData;
    }
    data[size] = val;
    size++;

}

//get: return element at index
int DynamicArray::get(int index) const{
    if(index < 0|| index >= size){
        std::cout << "Error: index out of bounds" << std::endl;
        return -1;
    }
    return data[index];

}

//set: assign val at index
void DynamicArray::set(int index, int val){
    if(index < 0 || index >= size){
        std::cout << "Error: index out of bounds" << std::endl;
        return;
    }
    data[index] = val;

}

//getSize
int DynamicArray::getSize() const{
    return size;

}

//getCapacity
int DynamicArray::getCapacity() const{
    return capacity;

}

//print
void DynamicArray::print() const{
    std::cout << "[";
    for(int i =0; i < size; i++){
        std::cout << data[i];
        if(i < size - 1){
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;

}

//copy constructors
DynamicArray::DynamicArray(const DynamicArray& other){
    size = other.size;
    capacity = other.capacity;
    data = new int[capacity];
    for(int i = 0; i < size; i++){
        data[i] = other.data[i];
    }


}


//copy assignment
DynamicArray& DynamicArray::operator=(const DynamicArray& other){

    if (this ==&other){
        return *this;

    }
    delete[] data;
    size = other.size;
    capacity = other.capacity;

    data = new int[capacity];
    for(int i = 0; i < size; i++){
        data[i] = other.data[i];
    }
    return *this;


}


