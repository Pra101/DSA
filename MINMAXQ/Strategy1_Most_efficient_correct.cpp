// Author: pra101
#include <bits/stdc++.h>
#include <cstdio>
#include <sys/time.h>
using namespace std;
#define int long long
#define float long double
#define ll long long
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef priority_queue<int> max_heap;
typedef priority_queue<int, vector<int>, greater<int>> min_heap;
#define pb push_back
#define d0(x) cout<<(x)<<" "
#define d1(x) cout<<(x)<<"\n"
#define d2(x,y) cout<<(x)<<" "<<(y)<<"\n"
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define all(v) (v).begin(),(v).end()
#define sz(v) (v).size()
#define enter(a) for (auto &it : (a)) cin >> it
unsigned int Z;
void srand_() {
	struct timeval tv;
	gettimeofday(&tv, NULL);
	Z = (tv.tv_sec ^ tv.tv_usec) | 1;
} 
int rand_() {
    srand_();
    return (Z *= 3) >> 1;
}
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
//-----------------------------------------------------------------------------------------------------------
struct custom_hash { // Credits: https://codeforces.com/blog/entry/62393
    static uint64_t splitmix64(uint64_t x) { // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
    template<typename L, typename R>
    size_t operator()(pair<L,R> const& Y) const{
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(Y.first * 31ull + Y.second + FIXED_RANDOM);
    }
};
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
//_-
int cas=0;
int cost(int sf,int ss){
    int ans=0;
    if((sf/2)<=ss)return sf;
    if(ss==0)ans+=(sf*(sf+1))/2;
    else {
	ans+=ss;
	int sz=((sf-ss)/(ss+1));
	int a = (sf-ss)%(ss+1);
	int b = (ss+1-a);
	ans+=((b)*((sz*(sz+1))/2)+(a)*(((sz+1)*(sz+2))/2));
    }
    return ans;
}
void Mamba_Mentality(){
    //cout<<"Case #"<<cas<<": ";
    int n,k;cin>>n>>k;
    vector<int> arr(n);enter(arr);
    int ct=1;
    int ans=0;
    priority_queue<pair<int,pair<int,int>>> pq;
    for(int i=1;i<n;i++){
	if(arr[i]==arr[i-1])ct++;
	else {
	    if(ct==1)ans++;
	    else pq.push({cost(ct,0)-cost(ct,1),{ct,0}});
	    ct=1;
	}
    }
    if(ct==1)ans++;
    else pq.push({cost(ct,0)-cost(ct,1),{ct,0}});
    while((k>0)&&!pq.empty()){
	pair<int,pair<int,int>> tp=pq.top();
	pq.pop();
	tp.second.second++;
	int ss=tp.second.second,sf=tp.second.first;
	tp.first=cost(sf,ss)-cost(sf,ss+1);
	if(tp.first>0)pq.push(tp);
	else ans+=sf;
	k--;
    }
    while(!pq.empty()){
	pair<int,pair<int,int>> tp=pq.top();
	int ss=tp.second.second,sf=tp.second.first;
	ans+=cost(sf,ss);
	pq.pop();
    }
    d1(ans);
    return ;
}
int32_t main(){
    fio;
    //#ifndef ONLINE_JUDGE
        //freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    //#endif
    int t=1;
    cin>>t;
    while(t--){
	cas++;
	Mamba_Mentality();
    }
    return 0;
}
