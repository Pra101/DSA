class NumArray {
public:
    vector<int> seg;
    vector<int> arr;
    int n;
    NumArray(vector<int>& nums) {
        n = nums.size();
        seg.assign(3*n,0);
        arr=nums;
        for(int i=0;i<n;i++)upd(1,i,0,n-1);
       // for(auto ele : seg)cout<<ele<<" ";
    }
    void upd(int idx,int index,int l,int r){
        if(index>r||index<l)return;
        if(l==r){
            seg[idx]=arr[index];
            return;
        }
        int mid=(l+r)/2;
        upd(2*idx,index,l,mid);
        upd(2*idx+1,index,mid+1,r);
        seg[idx]=seg[2*idx]+seg[2*idx+1];
    }
    void update(int index, int val) {
        arr[index]=val;
        upd(1,index,0,n-1);
        cout<<"\n";
        //for(auto ele : seg)cout<<ele<<" ";
    }
    int sum(int idx,int left,int right,int l,int r){
        if(left>r||right<l)return 0;
        if(left<=l&&right>=r)return seg[idx];
        int mid=(l+r)/2;
        return sum(2*idx,left,right,l,mid)+sum(2*idx+1,left,right,mid+1,r);
    }
    int sumRange(int left, int right) {
        return sum(1,left,right,0,n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
