/******************************************************************************
 arrayFunctions.cpp
******************************************************************************
 Name:Tauseen Ahmed
******************************************************************************
 Collaborators/outside sources used
(IMPORTANT! Write "NONE" if none were used):


2. In part (a), does it matter if the arrays passed in as arguments are allocated on the stack or the heap? Why or why not?
No it does not matter because the function only recieves a pointer and the length and has no way of knowing where  the 
memory came from, it only reads values through the pointer.

3. In part (b), what would happen if the first parameter were int* instead of int**? Why wouldn’t that work?
That would not work because the int* reassignment of the pointer would only be local and you would require int** to modify the caller's pointer.

 Reminder: you are to write your own code.
******************************************************************************
 AI conversation links:

 Step 2 (debugging tutor, if used):
   Most predominant issues were that I forgot a ; Didnt realize I needed to share Ai links which was only possible if I made an account. Non account / free services dont allow the share link function
   When creating the account the old chatgpt prompts were deleted

 Step 3 (code review for intersection):

 https://chatgpt.com/share/69af45db-1374-800f-9c5d-180618e87a54

 Step 3 (code review for insert):
https://chatgpt.com/share/69af4d5a-ee0c-800f-8f21-4d9365647dd1
******************************************************************************
 Overall notes (not to replace inline comments):


*/

#include<iostream>

/* intersection
   Parameters: pointer to first array, its length, pointer to second array, its length
   Returns: the number of values that appear in both arrays
*/
int intersection(int* arr1, int len1, int* arr2, int len2){
   int count = 0;
   for(int i = 0; i < len1; i++){
      bool found = false;
      for(int j = 0; j < len2; j++){
         if(arr1[i] == arr2[j]){
            found = true;
         }


      }
      if (found == true){
         count++;}
   }
   return count;

}

/* insert
   Parameters: pointer to a pointer to a dynamically allocated array, the array's length,
               the value to insert, and the index at which to insert it
   Returns: nothing (modifies the array through the pointer-to-pointer)
*/
void insert(int** arrPtr, int length, int value, int index){
   if(index < 0 || index > length) return;
   int* newArr = new int[length + 1];
   for(int i = 0; i < index; i++){
      newArr[i] = (*arrPtr)[i]; 
   }

   newArr[index] = value;

   for(int i = index; i < length; i++){
      newArr[i +1] = (*arrPtr)[i];

   }
   delete *arrPtr;
   *arrPtr = newArr;

}

// You can add a main function to test here but remove it before submitting
