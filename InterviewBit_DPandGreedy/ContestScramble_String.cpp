string a,b;
int dp[51][51][51][51];
int recur(int l1,int r1,int l2,int r2){
    if(l1==r1)return (a[l1]==b[l2]);
    if(dp[l1][r1][l2][r2]!=-1) return dp[l1][r1][l2][r2];
    int ans=0;
    for(int i=0;i<(r1-l1);i++){
        ans|=(recur(l1,i+l1,l2,i+l2)&&recur(l1+i+1,r1,l2+i+1,r2));
        if(ans)break;
        ans|=(recur(l1,i+l1,r2-i,r2)&&recur(l1+i+1,r1,l2,r2-i-1));
        if(ans)break;
    }
    return dp[l1][r1][l2][r2]=ans;
}
int Solution::isScramble(const string A, const string B) {
    a=A;
    b=B;
    int n = A.size();
    memset(dp,-1,sizeof(dp));
    return recur(0,n-1,0,n-1);
}
