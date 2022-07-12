// word break memo
unordered_set<string> us;
string s;
int N;
int dp[6501];
int recur(int idx){
    if(idx==N)return 1;
    if(dp[idx]!=-1)return dp[idx];
    int ans=0;
    string s_tp="";
    for(int i=0;i<20;i++){
        s_tp+=s[idx+i];
        if(us.count(s_tp)>0){
            ans|=recur(idx+i+1);
        }
        if(ans)break;
    }
    return dp[idx]=ans;
}
int Solution::wordBreak(string A, vector<string> &B) {
    us.clear();
    for(auto ss : B)us.insert(ss);
    s=A;
    N=A.size();
    memset(dp,-1,sizeof(dp));
    return recur(0);
}
// word break Tabular
int Solution::wordBreak(string s, vector<string> &B) {
    unordered_set<string> us;
    for(auto ss : B)us.insert(ss);
    int N=s.size();
    vector<int> dp(N+1,0);
    dp[N]=1;
    for(int idx=N-1;idx>=0;idx--){
        int ans=0;
        string s_tp="";
        for(int i=0;i<20;i++){
            s_tp+=s[idx+i];
            if(us.count(s_tp)>0){
                ans|=dp[idx+i+1];
            }
            if(ans)break;
        }
        dp[idx]=ans;
    }
    return dp[0];
}
