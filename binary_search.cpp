// To Binary search the exact Number 
while(1){
	  int data;
	  cin>>data;
	  int l=0,r=n-1,f=0,mid;//Make sure that l and 'r' are exact bounds because if input is just above r or
					                //just below 'l' then could cause out of bondary access
	  while(l<=r){
	        mid=l+(r-l)/2;
	        if(arr[mid]==data){
		          cout<<"found!! :)\n";
		          f=1;
		          break;
	        }
	        else if(data<arr[mid])r=mid-1;
	        else l=mid+1;
	  }
	  if(f==0)cout<<"Not Found :'(\n";
}
