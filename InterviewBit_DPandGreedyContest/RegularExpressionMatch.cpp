string a,b;
int n,m;
vector<vector<bool>> vis;
vector<vector<bool>> dp;
bool recur(int i,int j){
    if(j==m) return (i==n);
    if(i==n){
        if(b[j]=='*')return recur(i,j+1);
        return 0;
    }
    if(vis[i][j]) return dp[i][j];
    int ans=0;
    if(a[i]==b[j])ans|=recur(i+1,j+1);
    if(b[j]=='?')ans|=recur(i+1,j+1);
    if(b[j]=='*'){
        ans|=recur(i,j+1);
        ans|=recur(i+1,j);
    }
    vis[i][j]=true;
    return dp[i][j]=ans;
}
int Solution::isMatch(const string A, const string B) {
    a=A;b=B;
    n=a.size();m=b.size();
    dp=vector<vector<bool>>(n+4,vector<bool>(m+4,false));
    vis=vector<vector<bool>>(n+4,vector<bool>(m+4,false));
    return recur(0,0);
}
