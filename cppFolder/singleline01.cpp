#include<iostream>
int main(){
	int a; int b;
	// The message will be printed for the user
	std::cout<< "Insert the integer a. ";
	// The integer a will be recieved from the user
	std::cin >>a;
	b=a*a; // The square of a is assigned to b.
	std::cout<<"The sqaure of a is ";
	std::cout<<b;
	std::cout<<std::endl;
	return 0;
}
