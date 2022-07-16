const int inf=1e9+7;
class Solution {
public:
    string s;
    int n;
    int dp[100001][2];
    int recur(int idx,int f){
        if(idx==n)return 0;
        if(dp[idx][f]!=-1)return dp[idx][f];
        int ans=inf;
        if(!f){
            ans=min(ans,recur(idx+1,f)+(s[idx]!='0'));
            ans=min(ans,recur(idx+1,1)+(s[idx]!='1'));
        }
        else ans=min(ans,recur(idx+1,1)+(s[idx]!='1'));
        return dp[idx][f]=ans;
    }
    int minFlipsMonoIncr(string a) {
        s=a;
        n = s.size();
        memset(dp,-1,sizeof(dp));
        return recur(0,0);
    }
};
