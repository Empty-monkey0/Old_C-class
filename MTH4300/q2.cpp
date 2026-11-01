////q2.cpp
//% CXXFLAGS -std=c++11
#include<iostream>
#include<vector>
#include<string>

class Student {
private:
    std::string name_;
    double gpa_;
public:
    Student(std::string n, double g){
        this->name_ = n; this->gpa_ = g;
    }
    std::string getName() const {
        return this->name_;
    }
    double getGpa() const {
        return this->gpa_;
    }
};

void printRoster(const std::vector<Student>& roster) {
    for (int i = 0; i < roster.size(); i++) {
        std::cout << roster[i].getName() << ": "
                  << roster[i].getGpa() << "\n";
    }
}

int main(){
    std::vector<Student> cs4300 = {Student("Alice", 3.8), Student("Bob", 3.5), Student("Carol", 3.9)};
    printRoster(cs4300);
}