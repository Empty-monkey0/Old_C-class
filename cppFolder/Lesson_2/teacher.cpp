//
#include <iostream>
int main(){
	std::string w;
	std::cin >> w;
	long i;
	i=0;
	std::cout<<w[i]<<"\n";
	while(i<w.length()){
		i=i+1;
		if(w.length()>i){
			std::cout<<w[i]<<"\n";
		}	 
	}
	return 0;
}

