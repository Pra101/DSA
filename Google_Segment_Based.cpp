#include<bits/stdc++.h>
using namespace std;
#define int long long int
void update(int node,int start,int end,int idx,int val,vector<int> &A,vector<int> &tree,int flag=0){
   if(start== end){
      if(!flag)A[idx]+=val;
      tree[node]+=val;
   }
   else {
      int mid=(start+end)/2;
      if(start<=idx && idx<=mid){
         update(2*node+1,start,mid,idx,val,A,tree,flag);
      }
      else {
         update(2*node+2,mid+1,end,idx,val,A,tree,flag);
      }
      tree[node]=tree[2*node+1]+tree[2*node+2];
   }
}
int query(int node ,int start,int end,int l,int r,vector<int> &tree){
   if(r<start||end<l){
      return 0;
   }
   if(l<=start && end<=r){
      return tree[node];
   }
   int mid=(start+end)/2;
   int p1=query(2*node+1,start,mid,l,r,tree);
   int p2=query(2*node+2,mid+1,end,l,r,tree);
   return p1+p2;
}
vector<long long> solve (int n, int Q, vector<int> A, vector<vector<int> > query1) {
   // Type your code here
   vector<int> nums(3*n,0);
   vector<int> squ(3*n,0);
   for(int i=0;i<n;i++){
      update(0,0,n-1,i,A[i],A,nums,1);
      update(0,0,n-1,i,A[i]*A[i],A,squ,1);
   }
   vector<long long> f_res;
   for(auto ele : query1){
      if(ele[0]==0){
         int x= ele[1],y=ele[2];
         x--,y--;
         long long ans= query(0,0,n-1,x,y,nums);
         ans*=ans;
         ans-=query(0,0,n-1,x,y,squ);
         ans/=2;
         f_res.push_back(ans);
      }
      else {
         int x= ele[1]-1,y=ele[2];
         update(0,0,n-1,x,y*y-A[x]*A[x],A,squ,1);
         update(0,0,n-1,x,y-A[x],A,nums,0);
      }
   }
   return f_res;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int Q;
    cin >> Q;
    vector<int> A(N);
    for(int i_A = 0; i_A < N; i_A++) cin >> A[i_A];
    vector<vector<int> > query(Q, vector<int>(3));
    for (int i_query = 0; i_query < Q; i_query++)
    {
    	for(int j_query = 0; j_query < 3; j_query++)
	    cin >> query[i_query][j_query];
    }
    vector<long long> out_;
    out_ = solve(N, Q, A, query);
    for(int i_out_ = 0; i_out_ < (int)out_.size(); i_out_++)
    	cout << out_[i_out_] << endl;
}
