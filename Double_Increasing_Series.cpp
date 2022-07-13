const int md =1e9+7;
int dp[100001][21];
int recur(int idx,int a){
    if(a<0)return 0;
    if(idx==1)return dp[idx][a]=a;
    if(dp[idx][a]!=-1)return dp[idx][a];
    int ans=0;
    ans=(ans+recur(idx-1,a/2))%md;
    ans=(ans+recur(idx,a-1))%md;
    return dp[idx][a]=ans;
}
int Solution::solve(int A, int B) {
    memset(dp,-1,sizeof(dp));
    return recur(B,A);
}

// const int mod =1e9+7;
// int Solution::solve(int A, int B) {
//     int dp[A+1][B+1];
//     memset(dp, 0, sizeof(dp));
//     for(int i=1;i<=A;i++){
//         for(int j=1;j<=B;j++){
//             if(j==1){
//                 dp[i][j]=i;
//             }
//             else{
//                 dp[i][j]=dp[i-1][j]+dp[i/2][j-1];
//             }
//         }
//     }
//     return dp[A][B];
// }
