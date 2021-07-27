#include <bits/stdc++.h>
int solution(vector<int> &a, int s)
{
   unordered_map<int, int> prefixes;
   int n=a.size()+1;
   vector<int> p(n,0),q(n,0);
   prefixes[0]=1;
   p[0]=0;
   q[0]=0;

   for(int i=1;i<n;i++){
       p[i]=p[i-1]+a[i-1];
       q[i]=p[i]-s*i;
       if(!prefixes.count(q[i])){
	   prefixes[q[i]]=1;
       }
       else {
	    prefixes[q[i]]++;
       }
   }
    int result = 0;
   for(auto ele : prefixes){
	result=(ele.second*(ele.second-1))/2;
   }
   return res;
}
