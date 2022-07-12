const int md=1e9+7;
int dp[1000001];
int recur(int a){
    if(a<=0)return (a==0);
    if(dp[a]!=-1)return dp[a];
    int ans=0;
    for(int i=1;i<=6;i++){
        ans=(ans+recur(a-i))%md;
    }
    return dp[a]=ans;
}
int Solution::solve(int A) {
    memset(dp,-1,sizeof(dp));
    return recur(A);
}
