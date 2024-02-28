#include <bits/stdc++.h>
using namespace std;

long long pow2(long long k, long long sum) 
{
    long long res;
    if (k == 0) 
        return 1;
    
    res = pow2(k/2, sum);
    res = res * res % sum;
    if (k % 2 != 0) 
        res = res * 2 % sum;
    return res;
}

int main() 
{
    int T;
    long long a, b, k, ans, mi;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++) 
    {
       scanf("%lld %lld %lld", &a, &b, &k);
       //mi = min(a, b);
       ans = (a * pow2(k, a+ b)) % (a + b);
       ans = min(ans, a + b - ans);
       printf("#%d %d\n", tc, ans);
        
    }
}
