// got to learn these recurence relatively trivial and less intuitive
const long long mod=1e9+7;// 998244353
inline long long add(long long x,long long y){
    x+=y;
    if (x>=mod) return x-mod;
    return x;
}
inline long long mul(long long x,long long y){
    return (x*1ll*y)%mod;
}
string s;
int N;
long long dp[152][152];
long long recur(int l,int r){
    if(l>r)return 1;
    if(l==r)return 0;
    if(s[l]==')'||s[l]=='}'||s[l]==']'||s[r]=='('||s[r]=='{'||s[r]=='[')return 0;
    if(dp[l][r]!=-1)return dp[l][r];
    long long ans=0;
    for(int i=l+1;i<=r;i++){
        if(s[l]=='?'&&s[i]=='?')ans=add(ans,mul(3LL,mul(recur(l+1,i-1),recur(i+1,r))));
        else if(s[l]=='('){
            if(s[i]==')'||s[i]=='?')ans=add(ans,mul(recur(l+1,i-1),recur(i+1,r)));
        }
        else if(s[l]=='{'){
            if(s[i]=='}'||s[i]=='?')ans=add(ans,mul(recur(l+1,i-1),recur(i+1,r)));
        }
        else if(s[l]=='['){
            if(s[i]==']'||s[i]=='?')ans=add(ans,mul(recur(l+1,i-1),recur(i+1,r)));
        }
        else if(s[l]=='?'){
            if(s[i]==')'||s[i]=='}'||s[i]==']')ans=add(ans,mul(recur(l+1,i-1),recur(i+1,r)));
        }
    }
    return dp[l][r]=ans;
}
int Solution::solve(string A) {
    N=A.size();
    s=A;
    memset(dp,-1,sizeof(dp));
    return recur(0,N-1);
}
