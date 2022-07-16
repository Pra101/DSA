class Solution {
public:
    string a,b;
    int n,m;
    vector<vector<bool>> vis;
    vector<vector<bool>> dp;
    bool recur(int i,int j){
        if(j==m) return (i==n);
        if(i<n&&j<m&&vis[i][j]) return dp[i][j];
        int ans=0;
        if(a[i]==b[j])ans|=recur(i+1,j+1);
        if(b[j]=='.')ans|=recur(i+1,j+1);
        if(b[j]=='*'){
            for(int idx=i;idx<=n;idx++){
                ans|=recur(idx,j+1);
            }
        }
        vis[i][j]=true;
        return dp[i][j]=ans;
    }
    bool isMatch(string s, string p) {
        a=s;b=p;
        n=a.size();m=b.size();
        dp=vector<vector<bool>>(n+4,vector<bool>(m+4,false));
        vis=vector<vector<bool>>(n+4,vector<bool>(m+4,false));
        return recur(0,0);
    }
};
