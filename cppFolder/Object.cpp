// 3/12/25 Class

#include<iostream>


/* Problem 1 code
class CCAccount{
public:
	std::string cName;
	double balance;
	
};

int main(){
	CCAccount x;
	x.cName = "Alice"; // Alice owes 55.7 to the Bank
	x.balance = 55.7;
	CCAccount y;
	y.cName = "Bob"; // Bank owes Bob 12.1
	y.balance = -12.1;
	std::cout<<"The customer "<<x.cName<<" has balance ";
	std::cout<<x.balance<<"\n";
	std::cout<<"The customer "<<y.cName<<" has balance ";
	std::cout<<y.balance<<"\n";
	return 0;
} */


/* Problem 2 code
class CCAccount{
private:
	double balance;

public:
	std::string cName;
	void printStatement();
	void addCharge(double );

};

void CCAccount::printStatement(){
	std::cout<<"Customer name "<< cName<<"\n";
	std::cout<<"Balance: "<<balance<<"\n";

}

void CCAccount::addCharge(double c){
	balance = balance + c;
}

int main(){
	CCAccount x;
	x.cName = "Alice";
	x.addCharge(50.7);
	x.addCharge(5.0);
	CCAccount y;
	y.cName = "Bob";
	y.addCharge(-10.1);
	y.addCharge(3);
	x.printStatement();
	y.printStatement();
	return 0;

} */



class CCAccount{
private:
	double balance;

public:
	std::string cName;
	CCAccount(); // Constructor
	void printStatement();
	void addCharge(double );

};

void CCAccount::printStatement(){
	std::cout<<"Customer name: "<<cName<<"\n";
	std::cout<<"balance: "<<balance<<"\n";
	}
	
CCAccount CCAccount(){
	balance = 0.0;
} 

CCAccount::CCAccount(std::string n){
	cName = n;
	balance = 0.0;
}

int main(){
	CCAccount x;
	x.cName = "BOB";
	CCAccount y("Alice");
}


