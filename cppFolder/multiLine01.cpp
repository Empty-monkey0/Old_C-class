#include<iostream>
int main(){
	int a; int b;
	/* The user will be asked to insert an integer a
	The square of a will be calulated and the result 
	will be stored in the variable b */
	std::cout<< "Insert the integer a. ";
	std::cin >> a;
	b=a*a;
	std::cout<<"The sqaure of a is ";
	std::cout<<b;
	std::cout<<std::endl;
	return 0;
}
