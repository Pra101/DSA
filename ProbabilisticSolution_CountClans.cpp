//used hash values to count a particular set of values
// sets were counted using probabiltiies;
// and were modulated using a 64bit prime
const int md = 1e9+7;
const long long king = 12582917LL;
const long long lda=1099511628211LL;
long long primeFactors(int n)
{
    long long k=1LL;
    long long val=0LL;
    int f=0;
    while (n % 2 == 0)
    {
        if(!f){
            val=(val+(2LL*k)%lda)%lda;
            k=(k*1LL*king)%lda;
            f=1;
        }
        n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        f=0;
        while (n % i == 0)
        {
            if(!f){
                val=(val+(i*1LL*k)%lda)%lda;
                k=(k*1LL*king)%lda;
                f=1;
            }
            n = n/i;
        }
    }
    if (n > 2)val=(val+(n*1LL*k)%lda)%lda;
    return val;
}
int Solution::solve(vector<int> &A) {
    map<long long,int> ump;
    for(auto e  : A)ump[primeFactors(e)]++;
    int ans=1;
    for(auto e : ump)ans=(ans*1LL*e.second)%md;
    return ans;
}
