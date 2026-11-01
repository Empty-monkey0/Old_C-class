////maxOfThreeTimes.cpp
// Example 5a (You try!) - write maxOf for int, double, and std::string
#include <iostream>
#include <string>

// your three versions here:
int maxOf(int a, int b){
    if(a > b){
        return a;
    }
    else{return b;}
}
double maxOf(double a, double b){
    if(a > b){
        return a;
    }
    else{return b;}
}
std::string maxOf(std::string a, std::string b){
    if(a > b){
        return a;
    }
    else{return b;}
}



int main(){
    std::cout << maxOf(3, 7) << "\n";
    std::cout << maxOf(3.5, 2.1) << "\n";
    std::cout << maxOf(std::string("apple"), std::string("banana")) << "\n";
    return 0;
}