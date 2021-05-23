// How to find first max and second max without Sorting 
// Important algorithmic:
vecrtor<int> maxProduct(vector<int>& nums) {
    const int n =nums.size();
    int mx1=0,mx2=1;// random distripution
    
    if(nums[mx1]<nums[mx2])swap(mx1,mx2);// Just handling first two indexes
                                         // and ensuring that mx1 has a greater index;
    for(int i=2;i<n;i++){
        if(nums[i]>nums[mx1]){
            swap(mx1,mx2);// give mx1 to mx2
            mx1=nums[i];  // and give index of greatest element to mx1
        }
        else if(nums[i]>nums[mx2]) mx2=i; // just give index of second greatest element to mx2;
    }
    return {(nums[mx1]),(nums[mx2])}; //returned the valuses
}
