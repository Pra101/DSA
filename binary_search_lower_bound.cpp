while(1){
      int data;
      cin>>data;
      if(data<arr[0]){
              cout<<"Values does not exist!!\n";
              continue;
      }
      int l=0, r=n-1,mid;
      int ans=0;
      while(l<=r){
              mid=l+(r-l)/2;
              if(data<arr[mid])r=mid-1;
              else {
                    if(mid>ans)ans=mid;
                    l=mid+1;
              }
      }
      cout<<arr[ans]<<"\n";
}
