#include <stdio.h> 
#include <string.h> 
  
// phoneKeyPad[i] stores all characters that correspond to digit i in phone 
const char phoneKeyPad[10][5] = {"", "", "abc", "def", "ghi", "jkl","mno", "pqrs", "tuv", "wxyz"}; 

void  printWordsUtil(int number[], int curr_digit, char output[], int n) 
{ 
    // Base case, if current output word is prepared 
    int i; 
    if (curr_digit == n) 
    { 
        printf("%s ", output); 
        return ; 
    } 
  
    // Try all 3 possible characters for current digir in number[] 
    // and recur for remaining digits 
    for (i=0; i<strlen(phoneKeyPad[number[curr_digit]]); i++) 
    { 
        output[curr_digit] = phoneKeyPad[number[curr_digit]][i]; 
        
        printWordsUtil(number, curr_digit+1, output, n); 
        
		if (number[curr_digit] == 0 || number[curr_digit] == 1) 
            return; 
    } 
} 
  
// A wrapper over printWordsUtil().  It creates an output array and 
// calls printWordsUtil() 
void printWords(int number[], int n) 
{ 
    char result[n+1]; 
    result[n] ='\0'; 
    printWordsUtil(number, 0, result, n); 
} 

int main(void) 
{ 
    int number[] = {2, 3, 4}; 
    int n = sizeof(number)/sizeof(number[0]); 
    printWords(number, n); 
    return 0; 
} 
