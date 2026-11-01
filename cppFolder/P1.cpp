#include<iostream>
int main(){
	int a;
	int b;
	std::cout<< "Type the value for a and then the value for b?\n" ;
	std::cin >> a;
	std::cin >> b;
	int m;
	m = a*a + b*b*b-37*a*b;
	std::cout << m;
	std::cout << std::endl;
	return 0;
}

