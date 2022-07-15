int Solution::maxProfit(const vector<int> &A) {
    int min_ele=INT_MAX,mx_ans=0;
    for(auto ele : A){
        mx_ans=max(mx_ans,ele-min_ele);
        min_ele=min(min_ele,ele);
    }
    return mx_ans;
}
