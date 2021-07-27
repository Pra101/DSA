int solution(vector<int> &blocks){
    const int n=blocks.size();
    vector<int> mxl(n),mxr(n);
    for(int i=0;i<n;i++){
	if(i==0)mxl[i]=1;
	else {
	    if(blocks[i-1]>=blocks[i]){
		mxl[i]+=mxl[i-1];
		mxl[i]++;
	    }
	    else {
		mxl[i]=1;
	    }
	}
    }
    for(int i=n-1;i>=0;i--){
	if(i==n-1)mxr[n-1]=1;
	else {
	    if(blocks[i+1]>=blocks[i]){
		mxr[i]+=mxr[i+1];
		mxr[i]++;
	    }
	    else mxr[i]=1;
	}
    }
    int ans=0;
    for(int i =0;i<n;i++){
	ans=max(ans,mxr[i]+mxl[i]-1);
    }
    return ans;
}
void Mamba_Mentality(){
    
    vector<int> arr{1,5,5,2,6};
    cout<<solution(arr);
    return ;
}
