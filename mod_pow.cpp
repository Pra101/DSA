// for k^n : working fast code:

// Recursive 
int pow2(int k, int n){
    if(n==0)return 1;
    if(n==1)return k;
    int ans=pow2(k, n/2);
    ans=mul(ans,ans);
    if(n%2)ans=mul(ans,k);
    return ans;
}

// Iterative
int power(int x,int y){
    int ans=1;
    while(y){
        if (y&1) ans=mul(ans,x);
        x=mul(x,x);
        y>>=1;
    }
    return ans;
}
