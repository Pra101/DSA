int Solution::solve(string s) {
    int n = s.size();
    vector<vector<int>> dp(n,vector<int>(n,0));
    int ans=0;
    for(int gap=0;gap<n;gap++){
        for(int i=0,j=gap;i+gap<n;i++,j++){
            if(gap==0)dp[i][j]=1;
            else if(gap==1){
                if(s[i]==s[j])dp[i][j]=1;
            }
            else {
                if(s[i]==s[j]&&(dp[i+1][j-1]))dp[i][j]=1;
            }
            if(dp[i][j])ans++;
        }
    }
    return ans;
}
