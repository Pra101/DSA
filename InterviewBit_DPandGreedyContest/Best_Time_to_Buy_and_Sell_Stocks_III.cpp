const int ninf= -1e9;
int N;
int dp[500001][2][3];// The game was to adjust this value more accurately.
int recur(int idx,int f,int k,vector<int>& a){
    if(k>2)return ninf;
    if(idx==N)return ((f==0&&k<3)?0:ninf);
    if(dp[idx][f][k]!=-1)return dp[idx][f][k];
    int ans=ninf;
    if(!f)ans=max(ans,recur(idx+1,1,k+1,a)-a[idx]);
    else ans=max(ans,recur(idx+1,0,k,a)+a[idx]);
    ans=max(ans,recur(idx+1,f,k,a));
    return dp[idx][f][k]=ans;
}
int Solution::maxProfit(const vector<int> &A) {
    N=A.size();
    memset(dp,-1,sizeof(dp));
    vector<int> a=A;
    return recur(0,0,0,a);
}
