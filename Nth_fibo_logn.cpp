// Author: pra101 
#include <bits/stdc++.h>
#include<unordered_set>
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
typedef priority_queue<ppi> max_heap_ppi;
typedef priority_queue<int> max_heap_int;
typedef priority_queue<int, vector<int>, greater<int>> min_heap_int;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define endl "\n"
#define d0(x) cout<<(x)<<" "
#define d1(x) cout<<(x)<<"\n"
#define d2(x,y) cout<<(x)<<" "<<(y)<<"\n"
#define d3(x,y,z) cout<<(x)<<" "<<(y)<<" "<<(z)<<"\n"
#define d4(a,b,c,d) cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<"\n"
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define all(v) (v).begin(),(v).end()
#define sz(v) (v).size()
//for vector input
#define enter(a) for (auto &it : (a)) cin >> it
////////////////////////////////////////////For debugging//////////////////////////////////////////////////
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
//============================================
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
/*/-----------------------Modular Arithmetic---------------/*/
const int mod=1e9+7;
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
 //=============LIMITS=====================
const int maxn=1e6+100;
const int MaxN=1e5+100;
const int INF=1e16+7;

//-----------------------------Code begins----------------------------
/*
	Lookout for overflows!!
	Check array sizes!!
	Clear before test cases!!
	Use the correct modulo!!
	Check for corner cases!!
	Are you forgetting something?!
	Read problem statement carefully!!!
*/
//-_
int MXstd[2][2]={{1,1},{1,0}};
int dp[2][2];
void MXmul(int flag){
    int res[2][2];
    if(flag==0){
	for(int i=0;i<2;i++){
	    for(int j=0;j<2;j++){
		res[i][j]=0;
		for(int k=0;k<2;k++){
		    res[i][j]=add(res[i][j],mul(dp[i][k],dp[k][j]));
		}
	    }
	}
    }
    else if(flag==1){
	for(int i=0;i<2;i++){
	    for(int j=0;j<2;j++){
		res[i][j]=0;
		for(int k=0;k<2;k++){
		    res[i][j]=add(res[i][j],mul(dp[i][k],MXstd[k][j]));
		}
	    }
	}
    }
    for(int i=0;i<2;i++){
	for(int j=0;j<2;j++){
	    dp[i][j]=res[i][j];
	}
    }
	
}
void MXpower(int n){
    if(n==1)return;
    MXpower(n/2);
    MXmul(0);
    if(n%2==1) MXmul(1);
    return ;
}			    
void never_give_up(){
    int n;
    cin>>n;
    //memset(dp,0,sizeof(dp));
    n++;
    for(int i=0;i<2;i++){
	for(int j=0;j<2;j++){
	    dp[i][j]=MXstd[i][j];
	}
    }
    MXpower(n);
    cout<<dp[1][1]<<"\n";
    return ;
}
int32_t main(){
    fio;//Use "flush" to remove from buffer
     
    int t=1;
    //cin>>t;
    while(t--) {
        never_give_up();
    }
    return 0;
}
