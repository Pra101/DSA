int res;
string s;
int dp[1002][1002];
int recur(int l ,int r){
    if(l>r)return 0;
    if(dp[l][r]!=-1)return dp[l][r];
    if(l==r){
        int tp = ((s[l]-'A'>=0)&&(s[l]-'A'<26));
        if(tp)res++;
        return dp[l][r]=tp;
    }
    int ans1=recur(l+1,r);
    int ans2=recur(l,r-1);
    int ans3=recur(l+1,r-1);
    int ans=ans1+ans2-ans3;
    if(ans>(r-l+1-ans))res++;
    return dp[l][r]=ans;
}
int Solution::solve(string A) {
    res=0;
    s=A;
    int n=A.size();
    memset(dp,-1,sizeof(dp));
    recur(0,n-1);
    return res;
}
