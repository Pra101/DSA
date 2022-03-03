// Author: pra101
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
#define int long long
#define float long double
#define ll long long
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef vector<pii> vpi;
typedef priority_queue<int> max_heap_int;
typedef priority_queue<int, vector<int>, greater<int>> min_heap_int;
#define pb push_back
#define mp make_pair
#define endl "\n"
#define d0(x) cout<<(x)<<" "
#define d1(x) cout<<(x)<<"\n"
#define d2(x,y) cout<<(x)<<" "<<(y)<<"\n"
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define all(v) (v).begin(),(v).end()
#define sz(v) (v).size()
#define enter(a) for (auto &it : (a)) cin >> it
///////////////////////////////////////////////For debugging//////////////////////////////////////////////////
#define watch(x) cout<<(#x)<<" is "<<(x)<<"\n";
#define TRACE
#ifdef TRACE
    #define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cerr << name << " : " << arg1 << endl;
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ',');
        cerr.write(names, comma - names) << " : " << arg1<<" | ";
        __f(comma+1, args...);
    }
#else
    #define trace(...) 1
#endif
//==================================================
template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ ";
    for(auto v : V) os << v << " ";
    return os << "]";
}
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ ";
    for(auto s:S) os<<s<<" ";
    return os<<"}";
}
template<class T> ostream& operator<<(ostream &os, unordered_set<T> S){
    os << "{ ";
    for(auto s:S) os<<s<<" ";
    return os<<"}";
}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.first << "," << P.second << ")";
}
template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {
    os << "{ ";
    for(auto m:M) os<<"("<<m.first<<":"<<m.second<<") ";
    return os<<"}";
}
template<class L, class R> ostream& operator<<(ostream &os, unordered_map<L,R> M) {
    os << "{ ";
    for(auto m:M) os<<"("<<m.first<<":"<<m.second<<") ";
    return os<<"}";
}
/*/----------------------------------------Modular Arithmetic---------------------------------------/*/
const int mod=1e9+7;// 998244353
inline int add(int x,int y){
    x+=y;
    if (x>=mod) return x-mod;
    return x;
}
inline int sub(int x,int y){
    x-=y;
    if (x<0) return x+mod;
    return x;
}
inline int mul(int x,int y){
    return (x*1ll*y)%mod;
}
inline int power(int x,int y){
    int ans=1;
    while(y){
        if (y&1) ans=mul(ans,x);
        x=mul(x,x);
        y>>=1;
    }
    return ans;
}
inline int inv(int x){
    return power(x,mod-2);
}
//------------------------------------------------------------------------------------------------------------
const int maxn=1e6+100;
const int INF=1e16+7;
const int MXI = 2e5+5;  
const float PI = acos((float)-1);
const int xd[4] = {1,0,-1,0}, yd[4] = {0,1,0,-1};

//------------------------------------Check Points----------------------------------------------------
/*
	Lookout for overflows!!
	Check array sizes!!
	Clear buffer before other test cases!!
	Use the correct modulo num!!
	Check for corner-edge cases!!
	Are you forgetting something?!
	Read problem statement carefully!!!
	* floating point precision errors!!
*/
//-_
// Non lazy segment tree keep tree size atleast 3 times;;;;
void update(int node, int start, int end, int idx, int val,vector<int> &A,vector<int> &tree ,int flag=0){
    // node val = 0 at the start of update call;
    // flag gives the information that it is a genuine query 
    if(start == end)
    {
        if(!flag)A[idx] += val;
        tree[node] += val;
    }
    else
    {
        int mid = (start + end) / 2;
        if(start <= idx and idx <= mid) update(2*node+1, start, mid, idx, val,A,tree,flag);
        else update(2*node+2, mid+1, end, idx, val,A,tree,flag);
        tree[node] = tree[2*node+1] + tree[2*node+2];
    }
}
int query(int node, int start, int end, int l, int r,vector<int> & tree)
{
    if(r < start or end < l) return 0;
    if(l <= start and end <= r) return tree[node];
    int mid = (start + end) / 2;
    int p1 = query(2*node+1, start, mid, l, r,tree);
    int p2 = query(2*node+2, mid+1, end, l, r,tree);
    return (p1 + p2);
}
//int cas=0;//cout<<"Case #"<<cas<<": "<<ans<<"\n";
//when not getting answers: look for constraints or key observatoions;
pair<int,int> dfs(int idx,vector<vector<int>>& adj,vector<int>& vis){
    vis[idx]=1;
    int sz=adj[idx].size();
    pair<int,int> ans={0,idx};
    for(int i=0;i<sz;i++){
	int tp=adj[idx][i];
	if(!vis[tp])ans=max(ans,dfs(tp,adj,vis));
    }
    ans.first++;
    return ans;
}
void path(int idx,int tar,vector<vector<int>>& adj,vector<int>& ans,vector<int>& vis,stack<int>& st){
    vis[idx]=1;
    st.push(idx);
    if(idx==tar){
	while(!st.empty()){
	    ans.push_back(st.top());
	    st.pop();
	}
	return;
    }
    int sz=adj[idx].size();
    for(int i=0;i<sz&&((int)ans.size()==0);i++){
	int tp=adj[idx][i];
	if(!vis[tp])path(tp,tar,adj,ans,vis,st);
    }
    if((int)ans.size()==0)st.pop();
    return;
}
void Mamba_Mentality(){
    int n;cin>>n;
    vector<vector<int>> adj(n);
    int x,y;
    for(int i=0;i<n-1;i++){
	cin>>x>>y;
	x--,y--;
	adj[x].push_back(y);
	adj[y].push_back(x);
    }
    vector<int> vis(n,0);
    pair<int,int> nd1=dfs(0,adj,vis);
    for(auto &ele :vis)ele=0;
    pair<int,int> nd2=dfs(nd1.second,adj,vis);
    for(auto &ele :vis)ele=0;
    //cout<<nd1<<" "<<nd2<<"\n";
    vector<int> ans;
    stack<int> st;
    path(nd1.second,nd2.second,adj,ans,vis,st);
    //cout<<ans<<"\n";
    if((int)ans.size()%2==1)cout<<ans[(nd2.first)/2]+1;
    else cout<<ans[(nd2.first)/2-1]+1;
    return;
}
int32_t main(){
    fio;
    //#ifndef ONLINE_JUDGE
        //freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    //#endif
    auto start = std::chrono::high_resolution_clock::now();
    int t=1;
    //cin>>t;
    //cout<<PI<<"\n";
    while(t--) {
	//cas++;
        Mamba_Mentality();
    }
    auto stop = std::chrono::high_resolution_clock::now(); 
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start); 
    //cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl; 
    return 0;
}
/*
int32_t main(){
    // Get the string
    string str = "11,21,31,41,51,61"; 
    vector<int> v;
    // Get the string to be taken
    // as input in stringstream
    stringstream ss(str);
    // Parse the string
    for (int i; ss >> i;) {
        v.push_back(i);
        if (ss.peek() == ',')
            ss.ignore();
    }
    if (ss.rdbuf()->in_avail() == 1) continue;// to detect end charracter in input stream;
    // Print the words
    for (size_t i = 0; i < v.size(); i++) cout << v[i] << endl;
}
**/
