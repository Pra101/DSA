string a,b,c;
int n,m,p;
int dp[151][151];
int recur(int i,int j){
    if((i+j)==p)return ((i+j)==p);
    if(dp[i][j]!=-1)return dp[i][j];
    int ans=0;
    if(i<n&&((i+j)<p)&&(a[i]==c[i+j]))ans|=recur(i+1,j);
    if(j<m&&((i+j)<p)&&(b[j]==c[i+j]))ans|=recur(i,j+1);
    return dp[i][j]=ans;
}
int Solution::isInterleave(string A, string B, string C) {
    a=A;b=B;c=C;
    n=a.size();m=b.size();p=c.size();
    memset(dp,-1,sizeof(dp));
    return recur(0,0);
}
