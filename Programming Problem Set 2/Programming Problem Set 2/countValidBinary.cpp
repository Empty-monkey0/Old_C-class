/******************************************************************************
 countValidBinary.cpp
******************************************************************************
 Name: Tauseen Ahmed
******************************************************************************
 Collaborators/outside sources used
(IMPORTANT! Write "NONE" if none were used):



 Reminder: you are to write your own code.
******************************************************************************
 AI conversation links (if AI was used):



******************************************************************************
 Overall notes (not to replace inline comments):


*/

#include<iostream>

/* Complete the definition of the following function. The function should be recursive.
   Parameters: k, length of binary string (n), and ending digit, 0 or 1 (end)
   Returns: the number of k-separated binary strings of length n with ending digit end
*/
int kSeparated(int k, int n, int end){
   // base case
   if(n==1){
      return 1;
   }

   // If it end in 0 it can be either 0 or 1
   if(end == 0){
      return kSeparated(k, n-1, 0) + kSeparated(k,n-1,1);
   }
   
   //String ends in 1 and is short enough that only one
   if(n <= k+1){
      return 1;
   }

// otherwise the k zeros before one are forced to solve the reamining n-k-1
   return kSeparated(k, n - k - 1, 0) + kSeparated(k, n - k - 1, 1);

}

// You can add a main function to test here but comment it out before submitting






