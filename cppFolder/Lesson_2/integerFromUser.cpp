//
#include<iostream>
int main(){
	long integerFromUser;
	std::cin>>integerFromUser;
	long squareOfTheNumber;
	squareOfTheNumber=integerFromUser*integerFromUser;
	std::string message;
	message="The square of the inserted number is";
	std::cout<<message<<" "<<squareOfTheNumber<<"\n";
	return 0;
	
}
