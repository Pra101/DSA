vector<vector<int>> a;
int N;
int dp[20001][2];
int recur(int idx,int u_d){
    if(idx>N)return 0;
    if(idx==N)return 0;
    if(dp[idx][u_d]!=-1) return dp[idx][u_d];
    int ans=0;
    ans=max(ans,recur(idx+2,u_d)+a[u_d][idx]);
    ans=max(ans,recur(idx+2,1-u_d)+a[u_d][idx]);
    ans=max(ans,recur(idx+1,u_d));
    ans=max(ans,recur(idx+1,1-u_d));
    return dp[idx][u_d]=ans;
}
int Solution::adjacent(vector<vector<int> > &A) {
    a=A;
    N=a[0].size();
    memset(dp,-1,sizeof(dp));
    int ans1=recur(0,0);
    //memset(dp,-1,sizeof(dp));
    int ans2=recur(0,1);
    return max(ans1,ans2);
}
