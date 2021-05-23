// How to find first max and second max without Sorting 
// Important algorithm
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        const int n =nums.size();
        int mx1=0,mx2=1;
        if(nums[mx1]<nums[mx2])swap(mx1,mx2);
        for(int i=2;i<n;i++){
            if(nums[i]>nums[mx1]){
                int tmp_=mx1;
                mx1=i;
                mx2=tmp_;
                
            }
            else if(nums[i]>nums[mx2]){
                mx2=i;
            }
        }
        return (nums[mx1]-1)*(nums[mx2]-1);
    }
};
