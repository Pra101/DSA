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
//#define endl "\n"
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
//For debugging
#define watch(x) cout<<(#x)<<" is "<<(x)<<"\n";
//=========================================================
 //for vector
template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ ";
    for(auto v : V) os << v << " ";
    return os << "]";
}
//for set
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ ";
    for(auto s:S) os<<s<<" ";
    return os<<"}";
}
//for unordered_set
template<class T> ostream& operator<<(ostream &os, unordered_set<T> S){
    os << "{ ";
    for(auto s:S) os<<s<<" ";
    return os<<"}";
}
//for pair
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.first << "," << P.second << ")";
}
//for map
template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {
    os << "{ ";
    for(auto m:M) os<<"("<<m.first<<":"<<m.second<<") ";
    return os<<"}";
}
 //============================================

const int maxn=1e6+100;
const int MaxN=1e5+100;
const int mod=1e9+7;
//-----------------------------Code begins----------------------------

int32_t main(){
    //fio;//Use "flush" to remove from buffer
    int x,y,a,b,n,i;
    cin>>n;
    a=1LL;
    b=n;
    vpi arr={{1,n}};
    int count,sum,p;
    char ch1,ch2,ch3,ch4;

while(1){
	
    sort(all(arr));
    p=arr.size();
    //cout<<arr<<"\n";
    //watch(n);
    x=(n+1)/3+1;
    y=(2*n+1)/3;
    
    //region detecters==============
    count=0,sum=0;
    for(i=0;i<p;i++){
	count+=arr[i].second-arr[i].first+1;
	if(count>=x) break;
	sum+=arr[i].second-arr[i].first+1;
    }
    a=arr[i].first+x-sum-1;
    //=======================
    count=0,sum=0;
    for(i=0;i<p;i++){
	count+=arr[i].second-arr[i].first+1;
	if(count>=y) break;
	sum+=arr[i].second-arr[i].first+1;
    }
    b=arr[i].first+y-sum-1;
    //=======================
    //-------------queries---------------------------
	cout<<a<<endl;
	cin>>ch1;
	if(ch1=='E') return 0;
	cout<<b<<endl;
	cin>>ch2;
	if(ch2=='E') return 0;
    //--------------------------------------------------


    //////////////////////////CASES////////////////////////////////
    //Case 1
    if(ch1=='G'&&ch2=='G'){
	n-=x;
	vpi nar;
	for(i=0;i<p;i++){
	    if(a>=arr[i].first&&a<=arr[i].second)break;
	}
	if(a!=arr[i].second){
	    arr[i].first=a+1;
	    for(;i<p;i++) nar.push_back(arr[i]);
	}else{
	    i=i+1;
	    for(;i<p;i++) nar.push_back(arr[i]);
	}
	arr=nar;
    }
    //Case 2
    if(ch1=='L'&&ch2=='L'){
	n-=(n-y+1);
	vpi nar;
	for(i=0;i<p;i++){
	    if(b>=arr[i].first&&b<=arr[i].second)break;
	}
	if(arr[i].first!=b){
	    arr[i].second=b-1;
	    for(int che=0;che<=i;che++) nar.push_back(arr[che]);
	}else{
	    for(int che=0;che<i;che++) nar.push_back(arr[che]);
	}
	arr=nar;
    }
    //Classic case 3
    if(ch1=='L'&&ch2=='G'){
	n-=(y-x+1);
	vpi nar;
	vpi temp=arr;
	for(i=0;i<p;i++){
	    if(a>=arr[i].first&&a<=arr[i].second)break;
	}
	if(arr[i].first!=a){
	    arr[i].second=a-1;
	    for(int che=0;che<=i;che++){
		nar.push_back(arr[che]);
	    }
	}
	else{
	    for(int che=0;che<i;che++){
		nar.push_back(arr[che]);
	    }
	}
	//cout<<nar<<"\n";
	arr=temp;
	for(i=0;i<p;i++){
	    if(b>=arr[i].first&&b<=arr[i].second)break;
	}
	if(b!=arr[i].second){
	    arr[i].first=b+1;
	    for(;i<p;i++){
		nar.push_back(arr[i]);
	    }
	}
	else{
	    i=i+1;
	    for(;i<p;i++){
		nar.push_back(arr[i]);
	    }
	}
	arr=nar;
    }


    
    if(ch1=='G'&&ch2=='L'){
	cout<<b<<endl;
	cin>>ch3;
	if(ch3=='L'){//low

	    n-=(n-y+1);
	vpi nar;
	for(i=0;i<p;i++){
	    if(b>=arr[i].first&&b<=arr[i].second)break;
	}
	if(arr[i].first!=b){
	    arr[i].second=b-1;
	    for(int che=0;che<=i;che++) nar.push_back(arr[che]);
	}else{
	    for(int che=0;che<i;che++) nar.push_back(arr[che]);
	}
	arr=nar;

	    
	}else{
	    cout<<a<<endl;
	    cin>>ch4;
	    if(ch4=='G'){//high


		n-=x;
	vpi nar;
	for(i=0;i<p;i++){
	    if(a>=arr[i].first&&a<=arr[i].second)break;
	}
	if(a!=arr[i].second){
	    arr[i].first=a+1;
	    for(;i<p;i++) nar.push_back(arr[i]);
	}else{
	    i=i+1;
	    for(;i<p;i++) nar.push_back(arr[i]);
	}
	arr=nar;

		
	    }else{//classic case3

		n-=(y-x+1);
	vpi nar;
	vpi temp=arr;
	for(i=0;i<p;i++){
	    if(a>=arr[i].first&&a<=arr[i].second)break;
	}
	if(arr[i].first!=a){
	    arr[i].second=a-1;
	    for(int che=0;che<=i;che++){
		nar.push_back(arr[che]);
	    }
	}
	else{
	    for(int che=0;che<i;che++){
		nar.push_back(arr[che]);
	    }
	}
	arr=temp;
	for(i=0;i<p;i++){
	    if(b>=arr[i].first&&b<=arr[i].second)break;
	}
	if(b!=arr[i].second){
	    arr[i].first=b+1;
	    for(;i<p;i++){
		nar.push_back(arr[i]);
	    }
	}
	else{
	    i=i+1;
	    for(;i<p;i++){
		nar.push_back(arr[i]);
	    }
	}
	arr=nar;
	
	    }
	}
    }

}
    return 0;
}
