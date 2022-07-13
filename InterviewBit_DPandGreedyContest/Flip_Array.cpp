const int inf = 10001;
vector<int> arr;
int N;
int s;
int dp[101][20003];
// this recurisive function finds the minimum sign flips
// invoked in second when s has already been found by rec2.
// runs in quardractic time
int recur(int idx,int sum){
    if(idx==N){
        return ((sum==s)?0:inf);
    }
    if(dp[idx][sum+10001]!=-1)return dp[idx][sum+10001];
    int ans=inf;
    ans=min(ans,recur(idx+1,sum+arr[idx]));
    ans=min(ans,recur(idx+1,sum-arr[idx])+1);
    return dp[idx][sum+10001]=ans;
}
// invoked first
// this recurisive funtions finds the minimum sum in quadractic time
void rec2(int idx,int sum){
    if(idx==N){
        if(sum>=0)s=min(s,sum);
        return;
    }
    if(dp[idx][sum+10001]!=-1)return;
    rec2(idx+1,sum+arr[idx]);
    rec2(idx+1,sum-arr[idx]);
    dp[idx][sum+10001]=1;
}

int Solution::solve(const vector<int> &A) {
    arr=A;
    N=A.size();
    s=inf;
    memset(dp,-1,sizeof(dp));
    rec2(0,0);
    //cout<<s<<":";
    memset(dp,-1,sizeof(dp));
    return recur(0,0);
}
