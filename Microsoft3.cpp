int solution(vector<int> &a){
    int n = a.size();
    vector<int> arr=a;
    int f1=0,f2=0;
    for(int i=1;i<n;i++){
	if(f1==0){
	    if(i%2==0&&arr[i]>=arr[i-1])f1=1;
	    else if(i%2==1&&arr[i]<=arr[i-1])f1=1;
	}
	if(f2==0){
	    if(i%2==0&&arr[i]<=arr[i-1])f2=1;
	    else if(i%2==1&&arr[i]>=arr[i-1])f2=1;
	}
    }
    if(f1==0||f2==0)return 0;
    int ans=0;
    n--;
    for(int k=0;k<n+1;k++){
	arr.clear();
	for(int i=0;i<n+1;i++){
	    if(i!=k)arr.push_back(a[i]);
	}
	f1=0,f2=0;
	for(int i=1;i<n;i++){
	    if(f1==0){
		if(i%2==0&&arr[i]>=arr[i-1])f1=1;
		else if(i%2==1&&arr[i]<=arr[i-1])f1=1;
	    }
	    if(f2==0){
		if(i%2==0&&arr[i]<=arr[i-1])f2=1;
		else if(i%2==1&&arr[i]>=arr[i-1])f2=1;
	    }
	}
	if(f1==0||f2==0)ans++;
    }
    return ans;
}
