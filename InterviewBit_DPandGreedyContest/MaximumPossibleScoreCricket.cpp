int N;
vector<int> a,b;
int dp[1000001][2];
int recur(int idx,int f_s){
    if(idx==N)return 0;
    if(dp[idx][f_s]!=-1)return dp[idx][f_s];
    int ans=0;
    if(!f_s)ans=max(ans,recur(idx+1,f_s)+a[idx]);
    else ans=max(ans,recur(idx+1,f_s)+b[idx]);
    ans=max(ans,recur(idx+1,1-f_s)+1);
    return dp[idx][f_s]=ans;
}
int Solution::solve(vector<int> &A, vector<int> &B) {
    a=A;
    b=B;
    N=A.size();
    int ans=0;
    memset(dp,-1,sizeof(dp));
    ans=max(ans,recur(0,0));
    memset(dp,-1,sizeof(dp));
    ans=max(ans,recur(0,1));
    return ans;
}
