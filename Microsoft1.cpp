void solution(int n, vector<int> &R, vector<int> &C) {
    // write your code in C++14 (g++ 6.2.0)
    int m=R.size();
    vector<vector<int>> ans(n,vector<int>(n,0));
    for(int i=0;i<m;i++){
	ans[R[i]][C[i]]=-1;
    }
    int x,y;
    for(int i=0;i<m;i++){
	x=R[i];
	y=C[i];
	if(x>0&&y>0&&ans[x-1][y-1]!=-1)ans[x-1][y-1]++;
	if(x>0&&ans[x-1][y]!=-1)ans[x-1][y]++;
	if(x>0&&y<n-1&&ans[x-1][y+1]!=-1)ans[x-1][y+1]++;
	if(y>0&&ans[x][y-1]!=-1)ans[x][y-1]++;
	if(x<n-1&&y>0&&ans[x+1][y-1]!=-1)ans[x+1][y-1]++;
	if(x<n-1&&ans[x+1][y]!=-1)ans[x+1][y]++;
	if(x<n-1&&y<n-1&&ans[x+1][y+1]!=-1)ans[x+1][y+1]++;
	if(y<n-1&&ans[x][y+1]!=-1)ans[x][y+1]++;
    }
    for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
	    if(ans[i][j]==-1)cout<<"B";
	    else cout<<ans[i][j];
	}
	cout<<"\n";
    }
    return;
}
