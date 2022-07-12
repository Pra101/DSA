int N;
vector<int> arr;
long long dp[1<<20];
long long recur(int memo){
    if(__builtin_popcount(memo)==N)return 0LL;
    if(dp[memo]!=-1LL)return dp[memo];
    long long int ans=0;
    for(int i=0;i<N;i++){
        if((memo&(1<<i))==0){
            for(int j=i+1;j<N;j++){
                if((memo&(1<<j))==0){
                    int tp=memo^(1<<i);
                    tp=tp^(1<<j);
                    long long calc=recur(tp)+__gcd(arr[i],arr[j])*(__builtin_popcount(tp)/2LL);
                    if(calc>ans)ans=calc;
                }
            }
            //break;
        }
    }
    return dp[memo]=ans;
}
long Solution::solve(int A, vector<int> &B) {
    N=2*A;
    arr=B;
    memset(dp,-1,sizeof(dp));
    long long ans=recur(0);
    return ans;
}
