//Ways to color a 3xN Board
const int md = 1e9+7;
int dp[100001][5][5][5];
int recur(int idx,int a,int b,int c){
    if(idx==0)return 1;
    int ans=0;
    if(dp[idx][a+1][b+1][c+1]!=-1)return dp[idx][a+1][b+1][c+1];
    if(a==-1){
        for(int p=0;p<4;p++){
            for(int q=0;q<4;q++){
                for(int r=0;r<4;r++){
                    if((p)!=(q)&&(q)!=(r)) {
                        ans=(ans+recur(idx-1,(p)%4,(q)%4,(r)%4))%md;
                    }
                }
            }
        }
        return dp[idx][a+1][b+1][c+1]=ans;
    }
    for(int p=0;p<3;p++){
        for(int q=0;q<3;q++){
            for(int r=0;r<3;r++){
                if((((a+p)%4)!=((b+q)%4))&&(((b+q)%4)!=((c+r)%4))){
                    ans=(ans+recur(idx-1,(a+p)%4,(b+q)%4,(c+r)%4))%md;
                }
            }
        }
    }
    return dp[idx][a+1][b+1][c+1]=ans;
}
int Solution::solve(int A) {
    memset(dp,-1,sizeof(dp));
    return recur(A,-1,-1,-1);
}
