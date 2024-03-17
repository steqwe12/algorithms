long sumXor(long n) {		// inefficient
    uint64_t nn=n;
    long cnt=0;
    for (uint64_t i=0;i<=nn;i++){
        if( i+nn == (i^nn) ) cnt++;
    }
    return cnt;
}

long sumXor(long n) {		// efficient
    long cnt=1;
    while(n>1){
        if(n%2==1);
        else 
            { if(cnt==1) cnt=2;
            else cnt*=2; }
        n/=2;
    }
    return cnt;
}