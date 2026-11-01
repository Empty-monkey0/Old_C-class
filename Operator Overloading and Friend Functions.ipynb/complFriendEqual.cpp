////complFriendEqual.cpp
// Example 4c - You try! Write a friend operator== so that double == Compl works.
#include<iostream>

class Compl{
private:
    double re_;
    double im_;
public:
    Compl(double r, double i) : re_(r), im_(i) {}
    
    // Member ==: Compl == Compl
    bool operator==(const Compl& other) const {
        return this->re_ == other.re_ && this->im_ == other.im_;
    }
    
    // Declare friend operator== here so double == Compl works
    friend bool operator==(double n, const Compl& other);
    
};

// Define the friend function here
friend bool operator==(double n, const Compl& other){
    return n == other.re_ && other.im_ == 0; 
    
}

int main(){
    Compl z1(5, 0);
    Compl z2(3, 4);
    
    std::cout << (z1 == z2) << "\n";     // 0 (false)
    std::cout << (5.0 == z1) << "\n";    // should be 1 (true)
    std::cout << (5.0 == z2) << "\n";    // should be 0 (false)
    std::cout << (3.0 == z2) << "\n";    // should be 0 (false), imaginary part isn't 0
}