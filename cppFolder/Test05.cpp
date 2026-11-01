
#include<iostream>
//Problem 1
//int main(){
//   long integerFromUser;
//   std::cin>>integerFromUser;
//   long squareOfTheNumber;
//   squareOfTheNumber=integerFromUser*integerFromUser;
//   std::string message;
//  message="The square of the inserted number is";
//   std::cout<<message<<" "<<squareOfTheNumber<<"\n";
//   return 0;
//}

//Problem 2
//int main(){
//   long integerFromUser;
//   std::cin>>integerFromUser;
//   long squareOfTheNumber;
//   squareOfTheNumber=integerFromUser*integerFromUser;
//   std::string message;
//   message="The square of the inserted number is";
//   std::cout<<message<<" "<<squareOfTheNumber<<"\n";
//   return 0;
//}

//Problem 3
//int main(){
//   long a,b,m;
//   std::cin>>a>>b;
//   m=a;
//   if(m<b){
//   	m=b;
//	}
//   std::cout<<m<<"\n";
//   return 0;
//}


//Problem 4
//int main(){
//   double x;
//   std::cin>>x;
//   if((x>5) && (x<15) || (x>95) && (x<205)){
//   std::cout<<"yes\n";
//   }
//   else{
//   std::cout<<"no\n";
//   }
//   return 0;
//}

//Problem 5
//int main(){
//   double x; double largestNumber;
//   std::cin>>x; largestNumber=x; 
//   std::cin>>x;
//   while(x>0.0){
//      if(x>largestNumber){
//      largestNumber = x;
//      }
//      std::cin>>x;
//   }
//   std::cout<<largestNumber<<std::endl;
//   return 0;
//}

//Problem 6 max{a,b} + min{cde} + max{b,e}//
//int main(){
//   double a,b,c,d,e;
//   double result; 
//   std::cin>>a>>b>>c>>d>>e;
//   double maxab, mincde, maxbe;
//   maxab = a;
//   if(b>maxab){
//   maxab = b;
//   }
//   mincde = c;
//   if(d<mincde){
//   mincde = d;
//   }
//   if(e<mincde){
//   mincde = e;
//   }
//   maxbe = b;
//   if(e>maxbe){
//   maxbe = e;
//   }
//   result = maxab + mincde + maxbe;
//   std::cout<<result<<"\n";
//   return 0;
//}

// Problem 7
//int main(){
//    double a11, a12, a21, a22, b1, b2, x, y; 
//    std::cin>>a11>>a12>>a21>>a22>>b1>>b2;
//    double D=a11*a22-a12*a21;
//    y=(b2*a11-b1*a21)/D;
//    x = (b1*a22-b2*a12)/D;
//    
//    std::cout<< x<<" "<<y<<std::endl;      
//    return 0;
//}


// Problem 8
//int main(){
//    int m,a,b,c; 
//    std::cin>>m>>a>>b>>c;
//    int x=0;
//    int foundSolution = 0;
//    while((a*x+b)&&(foundSolution==0)){
//    	if((a*x+b)%m == c){
//   	foundSolution = 1;
//    	}
//    else{
//    ++x;
//    	}
//    }
//    if(foundSolution == 1){
//    std::cout<<x<<std::endl;
//    }
//    else{
//    	std::cout<<"There is no such x.";
//    	std::cout<<std::endl;
//    }    
//    return 0;
//}
//
// Problem 9
//int main(){
//    int m,n,a,b,c,d; 
//    std::cin >> m >> n >> a >> b >> c >> d;
//    int x = 0;
//    int foundSolution = 0;
//    while((x<m*n)&&(foundSolution ==0)){
//    	if ( ((a*x+b)%m == c) &&( (a*x+b)%n==d)){
//    	foundSolution = 1;
//    	}
//	else{
//	    ++x;
//	}
//    }
//    if(foundSolution==1){
//    std::cout<<x<<std::endl;
//    }
//    else{
//    std::cout<<"There is no such x.";
//    std::cout<<std::endl;
//    }
//    return 0;
//}



// Problem 10
//int main(){
//	long p, M;
//	std::cin>>p>>M;
//	long counter = 0;
//	long x=0; long temp;
//	while(x<M){
//		temp=1;
//		long i=0;
//		while(i<5){
//		temp = (temp*x)%p;
//		++i;
//		}
//		if (temp == (p-1)){
//		++counter;
//		}
//		++x;
//	}
//	std::cout<<counter<<"\n";
//	return 0;
//}


// Problem 11
/*
int main(){
	long x;
	long sumDigits=0;
	std::cin>>x;
	if(x<0){
	x=0;
	}
	while(x>0){
		sumDigits = sumDigits + (x%10);
		x = x/10;
	}
	std::cout<<sumDigits<<"\n";
	return 0;
}*/

// Problem 13
/*
int main(){  
    int input, first, len=0; 
    std::cin>>first;
    input=first;
    while(input>0){
        if(input==first){
            ++len;
        }
        else{
            if(len%2==0){
                first=input;
            }
            else{
                if(first==1){
                    if(input==2){
                        first=3;
                    }
                    else{
                        first=2;
                    }
                }
                else{
                    if(first==2){
                        if(input==1){
                            first=3;
                        }
                        else{
                            first=1;
                        }
                    }
                    else{
                        // first=3
                        if(input==1){
                            first=2;
                        }
                        else{
                            first=1;
                        }
                    }
                }
            }
            len=1; 
        }
        std::cin>>input;
    }
    for(int i=0;i<len;++i){
        std::cout<<first<<" ";
    }
    std::cout<<std::endl;
    return 0;
}
*/

// Problem 12
int main(){
	int first, last, previous, length;
	std::cin>>last; length = 1;
	first = last;
	previous = last;
	while(last!= 2){
		length = length+1;
		if(last==previous){
			first = 1- first;
			length=1;
			last=first;
		}
		previous= last;
		std::cin>>last;
	}
	int termToPrint = first;
	int counter=0;
	while(counter<length){
		std::cout << termToPrint <<" ";
		termToPrint = 1- termToPrint;
		counter=counter+1;
	}
	std::cout << std::endl;
	return 0;

}


// Problem 14







 


















