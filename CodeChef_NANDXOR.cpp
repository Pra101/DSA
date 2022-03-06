void NANDXOR(){
    int n,data;cin>>n;
    vector<pair<int,int>> arr;
    for(int i=0;i<n;i++){
	cin>>data;
	arr.push_back({data,i+1});
    }
    sort(all(arr));

    for(int i1=0;i1<n-3;i1++){
	for(int i2=i1+1;i2<n-2;i2++){
	    for(int i3=i2+1;i3<n-1;i3++){
		for(int i4=i3+1;i4<n;i4++){
		    int tp1=arr[i1].first;
		    int tp2=arr[i2].first;
		    int tp3=arr[i3].first;
		    int tp4=arr[i4].first;

		    if(__builtin_popcount(tp1^tp2)==__builtin_popcount(tp3^tp4)){
		    cout<<arr[i1].second<<" "<<arr[i2].second<<" "<<arr[i3].second<<" "<<arr[i4].second<<"\n";
		    return;
		    }
		    if(__builtin_popcount(tp1^tp3)==__builtin_popcount(tp2^tp4)){
		    cout<<arr[i1].second<<" "<<arr[i3].second<<" "<<arr[i2].second<<" "<<arr[i4].second<<"\n";
		    return;
		    }
		    if(__builtin_popcount(tp1^tp4)==__builtin_popcount(tp2^tp3)){
		    cout<<arr[i1].second<<" "<<arr[i4].second<<" "<<arr[i2].second<<" "<<arr[i3].second<<"\n";
		    return;
		    }
		    
		}
	    }
	}
    }
    cout<<"-1\n";
    return ;
}
