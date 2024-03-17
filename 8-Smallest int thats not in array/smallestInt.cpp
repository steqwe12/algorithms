#include <algorithm>

int solution(vector<int> &A) {
    std::sort(A.begin(), A.end());
    int index=-1,help=0;
    int prevNum=A[0];
    for (int num:A){
        if(num>0 && num-prevNum>1 && prevNum>=0 && num>1) {index=help;break;}
        if(num>0 && num-prevNum>1 && prevNum<0 && num>1){index=-2;break;}
        prevNum=A[help];
        help++;
    }
    if (help == A.size() && A[A.size()-1]>0) return A[A.size()-1]+1;
    if (index==-1 || index==-2) return 1;
    return (A[index-1])+1;
}
