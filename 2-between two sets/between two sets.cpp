#include <algorithm>
int getTotalX(vector<int> a, vector<int> b) {
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    
    int retVal=0;
    for (int i=a[a.size()-1];i<=b[0];i++){
        bool itsOk=true;
        
        for (int num : a){
            if (i%num != 0) itsOk=false;
        }
        
        for (int num : b){
            if (num%i != 0) itsOk=false;
        }
        
        if (itsOk) retVal++;         
    }
    return retVal;
}
