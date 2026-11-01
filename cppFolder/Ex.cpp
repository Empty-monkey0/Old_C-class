# include <iostream>

int main(){
	long x;
	long& w = x;
	long* aX;
	aX = &w;
	aX = &w;
	*aX = 100;
	x = x + 15;
	w = x + w;
	std::cout<< x << "\n";
	std::cout<< w << "\n";
	return 0;
} 


//Problem 2
/*
void f()*/
