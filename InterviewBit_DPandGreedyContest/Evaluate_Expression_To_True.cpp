const int md=1003;
string s;
pair<int,int> dp[151][151];
pair<int,int> recur(int l,int r){
    if(l==r) return {s[l]=='T',s[l]=='F'};
    if(dp[l][r].first!=-1)return dp[l][r];
    int ans1=0,ans2=0;
    for(int i=l;i<r;i++){
        if(!(s[i]=='T'||s[i]=='F')){
            pair<int,int> ret1=recur(l,i-1);
            pair<int,int> ret2=recur(i+1,r);
            if(s[i]=='|'){
                ans1=(ans1+(ret1.first*ret2.first)%md)%md;
                ans1=(ans1+(ret1.second*ret2.first)%md)%md;
                ans1=(ans1+(ret1.first*ret2.second)%md)%md;
                ans2=(ans2+(ret1.second*ret2.second)%md)%md;
            }
            if(s[i]=='&'){
                ans1=(ans1+(ret1.first*ret2.first)%md)%md;
                ans2=(ans2+(ret1.second*ret2.first)%md)%md;
                ans2=(ans2+(ret1.first*ret2.second)%md)%md;
                ans2=(ans2+(ret1.second*ret2.second)%md)%md;
            }
            if(s[i]=='^'){
                ans2=(ans2+(ret1.first*ret2.first)%md)%md;
                ans1=(ans1+(ret1.second*ret2.first)%md)%md;
                ans1=(ans1+(ret1.first*ret2.second)%md)%md;
                ans2=(ans2+(ret1.second*ret2.second)%md)%md;
            }
        }
    }
    return dp[l][r]={ans1,ans2};
}
int Solution::cnttrue(string A) {
    s=A;
    int n = A.size();
    memset(dp,-1,sizeof(dp));
    return recur(0,n-1).first;
}
