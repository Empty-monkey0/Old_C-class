////complPlusFromPlusEquals.cpp
#include<iostream>

class Compl {
private:
    double re_;
    double im_;
public:
    Compl(double r, double i) : re_(r), im_(i) {}
    double getRe() const { return this->re_; }
    double getIm() const { return this->im_; }

    void display() const {
        if (this->im_ >= 0)
            std::cout << this->re_ << " + " << this->im_ << "i";
        else
            std::cout << this->re_ << " - " << -this->im_ << "i";
    }

    Compl& operator+=(const Compl& other) {
        this->re_ += other.re_;
        this->im_ += other.im_;
        return *this;
    }

    // Write operator+ here, using operator+= internally.
    Compl operator+(const Compl& other) const{
        Compl result(*this);
        result += other;
        return result;
    }

};

int main(){
    Compl a(1, 2);
    Compl b(3, 4);
    Compl c = a + b;
    c.display();   // expect: 4 + 6i
    std::cout << "\n";
}