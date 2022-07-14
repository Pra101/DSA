const int ninf= -1e9;
vector<int> a;
int N,b;
int dp[501][2][502];
int recur(int idx,int f,int k){
    if(k>b)return ninf;
    if(idx==N)return ((f==0&&k<b)?0:ninf);
    if(dp[idx][f][k]!=-1)return dp[idx][f][k];
    int ans=ninf;
    if(!f)ans=max(ans,recur(idx+1,1,k+1)-a[idx]);
    else ans=max(ans,recur(idx+1,0,k)+a[idx]);
    ans=max(ans,recur(idx+1,f,k));
    return dp[idx][f][k]=ans;
}
int Solution::solve(vector<int> &A, int B) {
    N=A.size();
    memset(dp,-1,sizeof(dp));
    a=A;
    b=min(B+1,501);// The only game was to adjust this more accurately.
    // as in length less then 500 we cannot sell and purchase more then 500 times
    return recur(0,0,0);
}
