// don't get bogged down by confusing problem statements
//Tushar's Birthday Party
const int inf=1000001;
vector<int> b,c;
int N;
int dp[1002];
int recur(int cap){
    if(cap<0)return inf;
    if(cap==0)return 0;
    if(dp[cap]!=-1)return dp[cap];
    int ans=inf;
    for(int i=0;i<N;i++){
        ans=min(ans,recur(cap-b[i])+c[i]);
    }
    return dp[cap]=ans;
}
int Solution::solve(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    b=B;
    c=C;
    N=B.size();
    memset(dp,-1,sizeof(dp));
    int ret_ans=0;
    for(auto ele : A){
        ret_ans+=recur(ele);
    }
    return ret_ans;
}
