const int inf= -1e9;
vector<int> arr;
int N;
int dp[100001][2];
int recur(int idx,int f){
    if(idx==N)return ((f==0)?0:inf);
    if(dp[idx][f]!=-1) return dp[idx][f];
    int ans=inf;
    if(!f)ans=max(ans,recur(idx+1,1)-arr[idx]);
    else ans=max(ans,recur(idx+1,0)+arr[idx]);
    ans=max(ans,recur(idx+1,f));
    return dp[idx][f]=ans;
}
int Solution::maxProfit(const vector<int> &A) {
    arr=A;
    N=A.size();
    memset(dp,-1,sizeof(dp));
    return recur(0,0);
}
