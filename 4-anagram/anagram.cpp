#include <string>
int anagram(string s) {
    std::string firstHalf, secondHalf;
    
    int length = s.length();
    if (length%2==1) return -1;
    int halfLength = length / 2;

    firstHalf = s.substr(0, halfLength);
    secondHalf = s.substr(halfLength);
    
    int niz[halfLength];	std::memset(niz, 0, sizeof(niz));
    int numOfDiff=0;
    
    for (char c1 : firstHalf) {
        bool found=false;
        int index = 0;
        
        for (char c2 : secondHalf) {
            if (c1==c2 && niz[index]==0){
                found=true;
                niz[index]=1;
                break;
            }           
            index++;
        }
        if(found==false) numOfDiff++;
        
    }
    return numOfDiff;
}
