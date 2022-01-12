// Binary search lower bounds 
// Works perfectly
while(1){
  	int data;
	  cin>>data;
	  if(data>arr[n-1]){
	        cout<<"Values does not exist!!\n";
	        continue;
	  }
	  int l=0, r=n-1,mid;
	  int ans=n-1;
	  while(l<=r){
	      mid=l+(r-l)/2;
	      if(data<=arr[mid]){
		          if(mid<ans)ans=mid;
		          r=mid-1;
	      }
	  else l=mid+1;
    	  }
	  cout<<arr[ans]<<"\n";
}
