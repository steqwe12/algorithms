HackerRank problem Palindrome index  
Not 100% correct but passes all tests  
  
example: wcwcq ... qcwc; if ... is palindrome, program would return -1 even though it should return 0;  
because of branch else if(s[i]==s[j-1] && s[i+1]==s[j-2]) {indx=j;j--;}  
                                   else if(s[i+1]==s[j] && s[i+2]==s[j-1]) {indx=i;i++;}  
if conditions in both branches are true and program would return -1(because it entered branch 1), we should check if going into branch 2 would be a possible solution 
