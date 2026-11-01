/******************************************************************************
 countValidBinaryWarmup.cpp
******************************************************************************
 Name: Tauseen Ahmed
******************************************************************************
 Collaborators/outside sources used
(IMPORTANT! Write "NONE" if none were used):
https://www.w3schools.com/cpp/cpp_functions_recursion.asp


 Reminder: you are to write your own code.
******************************************************************************
 AI conversation links (if AI was used):



******************************************************************************
 Overall notes (not to replace inline comments):


*/

#include<iostream>

/* Complete the definition of the following function. The function should be recursive.
   Parameters: length of binary string (n) and ending digit, 0 or 1 (end)
   Returns: the number of 1-separated binary strings of length n with ending digit end
*/
int oneSeparated(int n, int end){
   // Base case
   if (n ==1){
      return 1;

   }
   // if the sequence ends with one the next needs to be 0
   if (end == 1){
      return oneSeparated(n-1,0);

   }
   // If the val in seq is 0 it can be either 0 or one
   return oneSeparated(n-1,0) + oneSeparated(n-1,1);
}

// You can add a main function to test here but comment it out before submitting






