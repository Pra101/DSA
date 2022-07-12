const int inf=1000007;
vector<int> a;
pair<int,int> dp[101][101];
pair<int,int> recur(int l,int r){
    if(l>r)return {inf,inf};
    if(l==r)return {0,a[l]};
    if(dp[l][r].first!=-1) return dp[l][r];
    pair<int,int> mn_={inf,inf};
    for(int i=l;i<r;i++){
        pair<int,int> tp1=recur(l,i);
        pair<int,int> tp2=recur(i+1,r);
        if(mn_.first>((tp1.second*tp2.second)+(tp1.first+tp2.first))){
            mn_.first=(tp1.second*tp2.second)+(tp1.first+tp2.first);
            mn_.second=(tp1.second+tp2.second)%100;
        }
    }
    return dp[l][r]=mn_;
}
int Solution::minSmoke(vector<int> &A) {
    a=A;
    int n = a.size();
    memset(dp,-1,sizeof(dp));
    return recur(0,n-1).first;
}
