////complStream.cpp
// Example 5b - You try! Write operator<< for Compl.
#include<iostream>

class Compl{
private:
    double re_;
    double im_;
public:
    Compl(double r, double i) : re_(r), im_(i) {}
    
    Compl operator+(const Compl& other) const {
        return Compl(this->re_ + other.re_, this->im_ + other.im_);
    }
    
    // Declare and define operator<< as a friend
    friend std::ostream& operator<<(std::ostream& os, const Compl& z);
    
};

// Define operator<< here
std::ostream& operator<<(std::ostream& os, const Compl& z){

    os << z.re_;
    if(z.im_ >= 0){
        os << "+" << z.im_ << "i";
    }
    else{
        os << " - " << (-z.im_) << "i";
    }
    return os;
}

int main(){
    Compl z1(3, 4);
    Compl z2(1, -2);
    
    std::cout << z1 << "\n";              // should print: 3 + 4i
    std::cout << z2 << "\n";              // should print: 1 - 2i
    std::cout << z1 + z2 << "\n";         // should print: 4 + 2i
    std::cout << z1 << " + " << z2 << " = " << z1 + z2 << "\n";
}