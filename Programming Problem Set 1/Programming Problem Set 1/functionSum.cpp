/******************************************************************************
 functionSum.cpp
******************************************************************************
 Name: Tauseen Ahmed
******************************************************************************
 Collaborators/outside sources used 
(IMPORTANT! Write "NONE" if none were used):
None


 Reminder: you are to write your own code.
******************************************************************************
 Overall notes (not to replace inline comments):


*/
#include<iostream>

int main(){
//Read the number of pairs
  int n;
  std::cin >> n;
  //Store result
  int result = 0;
  
  int sign = -1;
  
  //Looping through each pair of read x,y values
  for(int i = 0; i < n; i++){
  int x, y;
  std::cin >> x >> y;
  //Calculate f(x,y) = x^4 +y^3 - 2xy
  int f = (x*x*x*x) + (y*y*y) - (2*x*y);
  //Add or subtract f based on the current sign
  result += sign * f;
  //Flip the sign for the next pair
  sign *=-1;
  
  }
  //Final out
  std::cout << result << std::endl;
  
  return 0;
}
