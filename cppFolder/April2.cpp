//Hi there

/* you are to  assume that the name of the canidates belong to the set
You are not allowed to assume anything about the names
You are not allowed to assume anything about the names, however you are allowed to assume that one of the candidates is so good that he or she will get more than half of all the votes
(0,100)
*/

#include <iostream>

struct SN{
public:
	long name;
	long votes;
	SN* aNext

};

SN* push (SN* aT, long n, long v ){
	SN* aNT = new SN;
	aNT -> name = n;
	aNT -> votes = v;
	aNT -> aNext = aT;
	return aNT;
}
SN* pop(SN* aT){
	if (aT == nullptr){
		return nullptr;
	}
	SN* aNT = aT -> aNext;
	delete aT;
	return aNT;
}

SN* find(SN* aT, long n){
	if(aT == nullptr){
	return nullptr;
	}
	if (aT > name == n){
		return aT;
	}
	return find(aT -> aNext);
}




int main(){
	long maxVote = 0
	long winner = -1
	long vote;
	long count;
	
	int* aP;
	aP = new int[100];
	
	for(i=0,i<100,++i){
		aP[i] = 0;
	} 
	
	
	std::cin>>vote;
	while(vote > 0 ){
	aP[vote] += 1;
		if(aP[vote] > maxVote){
			if(vote == winner){
				count++;
			}
			else{
			count-=1;
			if(count< 1){
				winner = vote;
				count =1;
			}
		
		}
		std::cin>>vote;
	}
	

	
	
	
	std::cout <<winner<< " got " <<maxVote;
	std::cout <<"votes. \n",
	delete[] aP;
	
	
	
	
	return 0;
}


