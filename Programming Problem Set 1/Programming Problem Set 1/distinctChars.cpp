/******************************************************************************
 distinctChars.cpp
******************************************************************************
 Name: Tauseen Ahmed
******************************************************************************
 Collaborators/outside sources used 
(IMPORTANT! Write "NONE" if none were used):
NONE


 Reminder: you are to write your own code.
******************************************************************************
 Overall notes (not to replace inline comments):


*/
#include<iostream>
int main(){
// Declares three character variables
  char c1, c2, c3;
  
  // Read three characters from standard input
  std::cin >> c1 >> c2 >> c3;
//Assume all three characters are distinct
  int count = 3;
  // Check if all three characters are the same else subtract 1 for each matching pair.
  if(c1 == c2 && c2==c3){
    count = 1;
  }
  else if (c1 == c2 ){
    count--;
  }
  else if(c1 ==c3){
    count--;
  }
  else if (c2 == c3){
    count--;
  }
  // Outputs the number of distinct characters
  std::cout << count <<std::endl;
  return 0;
}
