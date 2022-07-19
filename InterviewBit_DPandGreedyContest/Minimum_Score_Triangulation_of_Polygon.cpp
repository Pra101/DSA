const int inf=1e9+7;
class Solution {
public:
    vector<int> arr;
    int dp[51][51];
    int recur(int l,int r){
        if(r-l<2)return 0;
        if(dp[l][r]!=-1)return dp[l][r];
        int ans=inf;
        for(int i=l+1;i<r;i++){
            ans=min(ans,recur(l,i)+recur(i,r)+arr[l]*arr[r]*arr[i]);
        }
        return dp[l][r]=ans;
    }
    int minScoreTriangulation(vector<int>& values) {
        arr=values;
        int n = arr.size();
        memset(dp,-1,sizeof(dp));
        return recur(0,n-1);
    }
};
