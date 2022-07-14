const int md = 1000000007;
int N;
int dp[1001][10001];
int recur(int idx,int sum){
    if(sum<0)return 0;
    if(idx==N)return (sum==0);
    if(dp[idx][sum]!=-1)return dp[idx][sum];
    int ans=0;
    for(int i=0;i<10;i++){
        if(idx==0&&i==0)continue;
        ans=(ans+recur(idx+1,sum-i))%md;
    }
    return dp[idx][sum]=ans;
}
int Solution::solve(int A, int B) {
    N=A;
    memset(dp,-1,sizeof(dp));
    return recur(0,B);
}
