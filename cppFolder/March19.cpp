//Constructors and copy assignment
#include<iostream>
struct SN{
public:
    double c;
    SN* aNext;
};
SN* push(SN* aT, double x){
    SN* aNT=new SN;
    aNT->c = x;
    aNT->aNext= aT;
    return aNT;
}
SN* pop(SN* aT){
    if(aT==nullptr){return nullptr;}
    SN* aNT=aT->aNext;
    delete aT;
    return aNT;
}
SN* copyStack(SN* aT){
    if(aT==nullptr){return nullptr;}
    SN* aNT=new SN;
    aNT->c=aT->c;
    aNT->aNext=copyStack(aT->aNext);
    return aNT;
}
class CCAccount{
private:
    double balance;
    SN* aTT;
public:
    std::string cName;
    CCAccount(std::string = "NoNameYet");
    CCAccount(CCAccount &);
    void addCharge(double );
    void printStatement();
    void operator=(CCAccount& );
    ~CCAccount();
};


CCAccount::CCAccount(CCAccount & copyFrom){
	cName = copyFrom.cName;
	balance = copyFrom.balance;
	aTT =  copyStack(copyFrom.aTT);
	
}

CCAccount::CCAccount(std::string n){
    cName=n; aTT=nullptr; balance=0.0;
}
void CCAccount::addCharge(double x){
    balance+=x; aTT=push(aTT,x);
}
void CCAccount::operator=(CCAccount& x){
    if(&x!=this){//prevent self-assignment
        cName=x.cName; balance=x.balance;
        while(aTT!=nullptr){
            aTT=pop(aTT);
        }
        aTT=copyStack(x.aTT);
    }
}
void CCAccount::printStatement(){
    std::cout<<"Name: "<<cName<<"\nBalance: "<<balance<<"\n";
    std::cout<<"Transaction history.\n";
    SN* aR=aTT;
    while(aR!=nullptr){
        std::cout<<aR->c<<" ";
        aR=aR->aNext;
    }
    std::cout<<"\n";
}
CCAccount::~CCAccount(){
    std::cout<<"I am destructor.\nName: "<<cName<<"\nAddress: ";
    std::cout<< this<<"\n";
    while(aTT!=nullptr){
        aTT=pop(aTT);
    }
}
int mainOld(){
    CCAccount x;
    x.cName="Alice";
    CCAccount y("Bob");
    x.addCharge(15.0);x.addCharge(55.01);
    y.addCharge(10.0);y.addCharge(20.0);
    std::cout<<"Address of x: "<<&x<<"\n";
    std::cout<<"Address of y: "<<&y<<"\n";
    {
        CCAccount z("Carl");
        z.addCharge(100.0);z.addCharge(200.0);
        std::cout<<"Address of z is"<<&z<<"\n";
        z.printStatement();
        std::cout<<"Be ready to see z destroyed\n";
    }
    x.printStatement();
    y.printStatement();
    CCAccount* aW;
    aW=new CCAccount("David");
    (*aW).addCharge(1000.0);(*aW).addCharge(2000.0);
    (*aW).printStatement();
    std::cout<<"The address of aW is "<<aW<<"\n";
    std::cout<<"We must de-allocate aW by ourselves to prevent ";
    std::cout<<"memory leak.\n";
    delete aW;
    return 0;
}
int main(){
    CCAccount x("Alice");
    x.addCharge(10.0); x.addCharge(20.0); x.addCharge(30.0);
    {
/*        CCAccount y;
        y = x; */
        CCAccount y=x;
        /*y.printStatement();*/
        y.cName="Bob";y.printStatement();
        std::cout<<"y is about to be destroyed\n";
    }
//    std::cout<<"We are outside of the block that created y.\n";
    std::cout<<"By now, the object y is gone. We still have x.\n";
    x.printStatement();
    std::cout<<"We printed the statement for x\n";
//    x=x;
//    x.printStatement();
    return 0;
}





