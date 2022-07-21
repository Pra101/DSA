vector<vector<int>> mp;
string s;
int n;
int dp[1001];
int recur(int idx){
	if(idx==n)return 1;
	if(dp[idx]!=-1)return dp[idx];
	int ans=0;
	for(int i=idx;i<n;i++){
		if(mp[idx][i]){
			ans=add(ans,recur(i+1));
		}
	}
	return dp[idx]=ans;
}
void solve(){
    //cout<<"Case #"<<cas<<": ";
    cin>>s;
    n=s.size();
    mp=vector<vector<int>>(n,vector<int>(n,0));
    for(int gap=0;gap<n;gap++){
		for(int i=0,j=gap;i+gap<n;i++,j++){
			if(gap==0)mp[i][j]=1;
			else if(gap==1){
				if(s[i]==s[j])mp[i][j]=1;
			}
			else {
				if((s[i]==s[j])&&(mp[i+1][j-1]))mp[i][j]=1;
			}
		}
	}
	//trace(mp);
	memset(dp,-1,sizeof(dp));
	int ans=recur(0);
	d1(ans);
}
