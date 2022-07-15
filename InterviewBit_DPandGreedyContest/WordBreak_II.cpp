set<string> us;
string a;
int n;
void recur(int idx,string tmp_,vector<string>& ans){
    if(idx==n){
        if((int)tmp_.size()>0)ans.push_back(tmp_);
        return;
    }
    string s="";
    for(int i=idx;i<n&&((i-idx)<=20);i++){
        s+=a[i];
        if(us.count(s)>0){
            recur(i+1,tmp_+((idx!=0)?" ":"")+s,ans);
        }
    }
    return;
}
vector<string> Solution::wordBreak(string A, vector<string> &B) {
    vector<string> ans;
    n = A.size();
    a=A;
    us.clear();
    for(auto ele : B)us.insert(ele);
    recur(0,"",ans);
    return ans;
}
