#include <iostream>
#include <cstdio>

using namespace std;
int palindromeIndex(string s) {
	printf("%d  ", s.length());
    printf("%s\n", s.c_str());
    if (s.length()==1) return -1;
    int len=s.length();
    int indx=-1;
    
    if (len%2==0){    
        for (int i=0,j=len-1;i<j;i++,j--){
            if (s[i]==s[j]) continue;
            else {
                if (indx!=-1) return -1;
                else if(i+1==j) return i; // or j, doesnt matter             
                else if(s[i]==s[j-1] && s[i+1]==s[j-2]) {indx=j;j--;}
                else if(s[i+1]==s[j] && s[i+2]==s[j-1]) {indx=i;i++;}
                else return -1;
            }
        }
    }
    else { // len%2==1 
       for (int i=0,j=len-1;i<j;i++,j--){
            if (s[i]==s[j]) continue;
            else {
                if (indx!=-1) return -1; // or j, doesnt matter   
                else if(s[i]==s[j-1] && s[i+1]==s[j-2]) {indx=j;j--;}
                else if(s[i+1]==s[j] && s[i+2]==s[j-1]) {indx=i;i++;}
                else return -1;
            }
        } 
    }
    
    
    return indx;
}