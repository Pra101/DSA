string a,b;
int n,m;
int dp[701][701];
int recur(int idx,int i){
    if(i==m)return 1;
    if(idx==n)return 0;
    if(dp[idx][i]!=-1)return dp[idx][i];
    int ans=0;
    if(a[idx]==b[i])ans+=recur(idx+1,i+1);
    ans+=recur(idx+1,i);
    return dp[idx][i]=ans;
}
int Solution::numDistinct(string A, string B) {
    a=A;b=B;
    n=a.size(),m=b.size();
    memset(dp,-1,sizeof(dp));
    return recur(0,0);
}
