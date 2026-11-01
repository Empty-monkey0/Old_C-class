////fractionEqInt.cpp
#include<iostream>

class Fraction {
private:
    int num_;
    int den_;
public:
    Fraction(int n, int d) : num_(n), den_(d) {}
    int getNum() const { return this->num_; }
    int getDen() const { return this->den_; }
    friend bool operator==(int n, const Fraction& other);

};

// Write your operator== here
bool operator==(int n, const Fraction& other){
    //return other.num_ == n * other.den_;
    return other.num_ / other.den_ == n && other.num_ % other.den_ == 0;
}

int main(){
    Fraction f(6, 3);
    if (2 == f) { std::cout << "equal!\n"; }

    Fraction g(7, 3);
    if (2 == g) { std::cout << "g equals 2\n"; }
    else        { std::cout << "g does not equal 2\n"; }
}