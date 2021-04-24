// for k^n : working fast code: Learn::
int pow2(int k, int n){
    if(n==0)return 1;
    if(n==1)return k;
    int ans=pow2(k, n/2);
    ans=mul(ans,ans);
    if(n%2)ans=mul(ans,k);
    return ans;
}
