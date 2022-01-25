class NumArray {
public:
    vector<int> arr,num;
    int n;
    NumArray(vector<int>& nums) {
        n=nums.size();
        num=nums;
        arr.assign(n,0);
        for(int i=0;i<n;i++)upd(i+1,nums[i]);
    }
    void upd(int idx,int diff){
        for(int k=idx;k<=n;k+=k&(-k))arr[k-1]+=diff;
    }
    void update(int index, int val) {
        upd(index+1,val-num[index]);
        num[index]=val;
    }
    int sumRange(int left, int right) {
        int ans=0;
        for(int k=right+1;k>0;k-=(k&(-k)))ans+=arr[k-1];
        for(int k=left;k>0;k-=(k&(-k)))ans-=arr[k-1];
        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
