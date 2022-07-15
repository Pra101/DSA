const int inf=1e9+7;
string a,b;
int n,m;
int dp[451][451];
int recur(int i,int j){
    if(i==n&&j==m)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int ans=inf;
    if(i<n&&j<m)ans=min(ans,recur(i+1,j+1)+(a[i]!=b[j]));//replace or continue
    if(i<n)ans=min(ans,recur(i+1,j)+1);//insert
    if(j<m)ans=min(ans,recur(i,j+1)+1);//delete
    return dp[i][j]=ans;
} 
int Solution::minDistance(string A, string B) {
    a=A;b=B;
    n=A.size();m=B.size();
    memset(dp,-1,sizeof(dp));
    return recur(0,0);
}
