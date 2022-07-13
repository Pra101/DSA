vector<int> a,b;
int N;
int dp[1001][1001];
int recur(int idx,int cost){
    if(idx==N)return 0;
    if(dp[idx][cost]!=-1) return dp[idx][cost];
    int ans=0;
    if(cost-b[idx]>=0)ans=max(ans,recur(idx+1,cost-b[idx])+a[idx]);
    ans=max(ans,recur(idx+1,cost));
    return dp[idx][cost]=ans;
}
int Solution::solve(vector<int> &A, vector<int> &B, int C) {
    a=A;
    b=B;
    N=A.size();
    memset(dp,-1,sizeof(dp));
    return recur(0,C);
}
