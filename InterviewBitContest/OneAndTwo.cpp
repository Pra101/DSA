// Recurrence relation looked like a (n+1)th term of Fibonacci dp[i]=dp[i-1]+dp[i-1](Question subtract one or two)
// Hense was solvable in logrithmic time using nth fibonnaci number
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
void multiply(long long F[2][2], long long M[2][2]);
void power(long long F[2][2], long long n);
// Function that returns nth Fibonacci number
long long fib(long long n)
{
    long long F[2][2] = {{1, 1}, {1, 0}};
    if (n == 0)
        return 0;
    power(F, n - 1);

    return F[0][0];
}
// Optimized version of power() in method 4
void power(long long F[2][2], long long n)
{
    if(n == 0 || n == 1)
    return;
    long long M[2][2] = {{1, 1}, {1, 0}};
    
    power(F, n / 2);
    multiply(F, F);
    
    if (n % 2 != 0)
        multiply(F, M);
}
void multiply( long long F[2][2], long long M[2][2])
{
    long long x = add(mul(F[0][0] ,M[0][0]) , mul(F[0][1] , M[1][0]));
    long long y = add(mul(F[0][0] , M[0][1]) , mul(F[0][1] , M[1][1]));
    long long z = add(mul(F[1][0] , M[0][0]) , mul(F[1][1] , M[1][0]));
    long long w = add(mul(F[1][0] , M[0][1]) , mul(F[1][1] , M[1][1]));
    
    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}
long long count(long long n)
{
    return (fib(n+3)-2);
}
int Solution::oneAndTwo(vector<int> &A) {
    int sum=0;
    for(auto ele : A)sum=add(sum,count(ele));
    return sum;
}
