#Flood Fill
const int xd[4] = {1,0,-1,0}, yd[4] = {0,1,0,-1};
int ct=0;
vector<string> arr;
void dfs(int i,int j,int n,int m,vector<vector<int>>& vis){
    if((i>-1)&&(j>-1)&&(i<n)&&(j<m)&&(!vis[i][j])&&(arr[i][j]=='.'||arr[i][j]=='G')){
	vis[i][j]=1;
	if(arr[i][j]=='G')ct++;
	for(int k=0;k<4;k++)dfs(i+xd[k],j+yd[k],n,m,vis);
    }
    return;
}
void Mamba_Mentality(){
    int n,m;cin>>n>>m;
    arr.clear();
    string s;
    for(int i=0;i<n;i++){cin>>s;arr.push_back(s);}
    int ctg=0;
    for(int i=0;i<n;i++){
	for(int j=0;j<m;j++){
	    if(arr[i][j]=='G')ctg++;
	    if(arr[i][j]=='B'){
		for(int k=0;k<4;k++){
		    if((i+xd[k]>-1&&i+xd[k]<n)&&(j+yd[k]>-1&&j+yd[k]<m)){
			if(arr[i+xd[k]][j+yd[k]]=='G'){
			    cout<<"No\n";
			    return;
			}
			if(arr[i+xd[k]][j+yd[k]]=='.')arr[i+xd[k]][j+yd[k]]='#';
		    }
		}
	    }
	}
    }
    if(ctg==0){
	cout<<"Yes\n";
	return;
    }
    if(arr[n-1][m-1]=='#'){
	cout<<"No\n";
	return;
    }
    ct=0;
    vector<vector<int>> vis(n,vector<int>(m,0));
    dfs(n-1,m-1,n,m,vis);
    if(ct==ctg)cout<<"Yes\n";
    else cout<<"No\n";
    return ;
}
