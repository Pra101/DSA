const int inf=1051;
string a,b;
int n,cost;
int dp[1001][1001][2];
int recur(int l,int r,int f){
    if(l>r)return 0;
    if(l==r)return a[l]!=b[l];
    if(dp[l][r][f]!=-1)return dp[l][r][f];
    int ans=inf;
    if(!f){
        ans=min(ans,recur(l+1,r,0)+(a[l]!=b[l]));
        ans=min(ans,recur(l,r-1,0)+(a[r]!=b[r]));
        ans=min(ans,recur(l,r,1)+cost);
    }
    else {
        ans=min(ans,recur(l+1,r-1,1)+(a[l]!=b[r])+(a[r]!=b[l]));
        //ans=min(ans,recur(l,r-1,f)+(a[r]!=b[l]));
    }
    return dp[l][r][f]=ans;
}
int Solution::solve(string A, string B, int C) {
    a=A;
    b=B;
    n=A.size();
    cost=C;
    memset(dp,-1,sizeof(dp));
    return recur(0,n-1,0);
}
