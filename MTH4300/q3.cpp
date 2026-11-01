////q3.cpp
#include<iostream>
#include<string>

class Roster{
private:
    std::string* names_;
    int size_;
public:
    Roster(int n){
        this->size_ = n;
        this->names_ = new std::string[n];
    }
    
    // Write the destructor:
    ~Roster(){
        delete[] this->names_;
    }
    
    // Write the copy constructor:
    Roster(const Roster& other){
        this->size_ = other.size_;
        this->names_ = new std::string [other.size_];
        for(int i = 0; i < other.size_; i++){
            this->names_[i] = other.names_[i];
        }
    }
    
    // Write the copy assignment operator:
    Roster& operator=(const Roster& other){
        if(this != &other){
            delete[] this->names_;
            this -> size_ = other.size_;
            this->names_ = new std::string [other.size_];
            for(int i =0; i < other.size_; i++){
                this->names_[i] = other.names_[i]; 
            }
        }
        return *this;
    }
    
    void setName(int i, std::string name){
        this->names_[i] = name;
    }
    void print() const {
        for(int i = 0; i < this->size_; i++){
            std::cout << this->names_[i] << "\n";
        }
    }
};

int main(){
    Roster r1(3);
    r1.setName(0, "Alice");
    r1.setName(1, "Bob");
    r1.setName(2, "Carol");
    
    Roster r2 = r1;        // copy constructor
    r2.setName(0, "Zara");
    
    std::cout << "r1:\n";
    r1.print();  // Should still be Alice, Bob, Carol
    std::cout << "r2:\n";
    r2.print();  // Should be Zara, Bob, Carol
    
    Roster r3(1);
    r3.setName(0, "Nobody");
    r3 = r1;               // copy assignment
    r3.setName(1, "Eve");
    
    std::cout << "r1 after assignment:\n";
    r1.print();  // Should still be Alice, Bob, Carol
    std::cout << "r3:\n";
    r3.print();  // Should be Alice, Eve, Carol
}