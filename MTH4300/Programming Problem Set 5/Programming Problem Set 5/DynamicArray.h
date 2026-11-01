/******************************************************************************
 DynamicArray.h
******************************************************************************
 Name: Tauseen Ahmed
******************************************************************************
 AI conversation links (Step 2 and/or Step 3):
I will place all Ai and questions on 5c

******************************************************************************
 Overall notes (not to replace inline comments):


*/

// Include guard: prevents this header from being included more than once
// during compilation (which would cause duplicate definition errors).
#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include<iostream> // no other headers should be added

// this file should not contain a main function
// The DynamicArray class should be defined here (declarations only)

class DynamicArray
{
    /* Write the class declaration */
    private:
        int* data; // pointer to dynamically allocated arrray
        int size;   // number of elements currently stored
        int capacity;   // total allocated slots
    public:
        DynamicArray(int cap = 10); //constructor
        ~DynamicArray();            //destructor

        void push_back(int val);    // append element
        int get(int index) const;   //acces element by index
        void set(int index,int val);    // modify element by index
        int getSize() const;            // return current size
        int getCapacity() const;    // return curent capacity
        void print() const;         // print in [1,2,3] format
        DynamicArray(const DynamicArray& other);    // copy constructor
        DynamicArray& operator=(const DynamicArray& other); //copy assignment

};

#endif
