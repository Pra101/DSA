const int mod=1e9+7;
inline int add(int x,int y){
    x+=y;
    if (x>=mod) return x-mod;
    return x;
}
inline int mul(int x,int y){
    return (x*1ll*y)%mod;
}
inline int power(int x,int y){
    int ans=1;
    while(y){
        if (y&1) ans=mul(ans,x);
        x=mul(x,x);
        y>>=1;
    }
    return ans;
}
inline int inv(int x){
    return power(x,mod-2);
}
map<int,int> primeFactors(int n)
{
    map<int,int> ans;
    int f=0;
    while (n % 2 == 0)
    {
        f++;
        n/=2;
    }
    if(f>0)ans[2]=f;
    for (int i = 3; i*i <= n; i = i + 2)
    {
        f=0;
        while (n % i == 0)
        {
            f++;
            n/=i;
        }
        if(f>0)ans[i]=f;
    }
    if (n > 2)ans[n]++;
    return ans;
}
int Solution::findPaths(vector<int> &A) {
    map<int,int> mp;
    for(auto ele : A){
        map<int,int> got=primeFactors(ele);
        for(auto e: got){
            //cout<<e.first<<":"<<e.second<<" ";
            mp[e.first]+=e.second;
        }
        //cout<<"|";
    }
    int sum=0;
    for(auto e : mp){
        //cout<<e.first<<":"<<e.second<<"  ";
        sum+=e.second;
    }
    vector<int> dp(sum+1,0);
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=sum;i++){
        dp[i]=i;
        dp[i]=mul(dp[i],dp[i-1]);
    }
    int ans=dp[sum];
    for(auto e : mp){
        ans=mul(ans,inv(dp[e.second]));
    }
    return ans;
}
