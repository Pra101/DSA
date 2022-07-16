const int inf=1e9+7;
string s;
int n,k;
int dp[151][151][151];
int recur(int idx,int prev,int kk){
    if(idx==n){
        //cout<<kk<<":";
        if(kk==k&&prev!=idx){
            int w=0,b=0;
            for(int i=prev;i<idx;i++){
                if(s[i]=='W')w++;
                else b++;
            }
            return (b*w);
        }
        else return inf;
    }
    if(dp[idx][prev+1][kk]!=-1)return dp[idx][prev+1][kk];
    int ans=inf;
    int w=0,b=0;
    for(int i=prev;i<=idx;i++){
        if(s[i]=='W')w++;
        else b++;
    }
    ans=min(ans,recur(idx+1,idx+1,kk+1)+((b)*(w)));
    ans=min(ans,recur(idx+1,prev,kk));
    return dp[idx][prev+1][kk]=ans;
}
int Solution::arrange(string A, int B) {
    s=A;
    n=A.size();
    k=B;
    memset(dp,-1,sizeof(dp));
    int ans=recur(0,0,1);
    return ((ans>=inf)?-1:ans);
}
