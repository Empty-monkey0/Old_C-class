/******************************************************************************
 countValidBinaryChallenge.cpp
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

/* Complete the definition of the following function. The function should be recursive
   and should NOT call oneSeparated or any equivalent helper that splits by ending digit.
   Parameters: length of binary string (n)
   Returns: the total number of 1-separated binary strings of length n
*/
int oneSeparatedChallenge(int n){
   if(n == 1){return 2;}
   if(n == 2){return 3;}
   return oneSeparatedChallenge(n-1) + oneSeparatedChallenge(n-2);
}

// You can add a main function to test here but comment it out before submitting