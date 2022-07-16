// simple counting style DP
const int md=1e9+7;
class Solution {
public:
    int m,n;
    int dp[51][51][51];
    int recur(int i,int j,int ml){
        if(i<0||i>=m||j<0||j>=n)return 1;
        if(dp[i][j][ml]!=-1)return dp[i][j][ml];
        if(ml==0)return 0;
        int ans=0;
        ans=(ans+recur(i+1,j,ml-1))%md;
        ans=(ans+recur(i-1,j,ml-1))%md;
        ans=(ans+recur(i,j+1,ml-1))%md;
        ans=(ans+recur(i,j-1,ml-1))%md;
        return dp[i][j][ml]=ans;
    }
    int findPaths(int mm, int nn, int maxMove, int startRow, int startColumn) {
        m=mm;
        n=nn;
        memset(dp,-1,sizeof(dp));
        return recur(startRow,startColumn,maxMove);
    }
};
