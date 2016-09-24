#include <bits/stdc++.h>
using namespace std;

long long int a, b, c, d, e, f,result[100005];

int main()
{
    //freopen("in.txt","r",stdin);
    long long int n, caseno = 0, cases;
    scanf("%lld", &cases);
    while( cases-- ) {
        memset(result,0,sizeof(result));
        scanf("%lld %lld %lld %lld %lld %lld %lld", &result[0], &result[1], &result[2], &result[3], &result[4], &result[5], &n);

        for(int i=6; i<=n; i++)
        {
            result[i] = (result[i-1]+result[i-2]+result[i-3]+result[i-4]+result[i-5]+result[i-6])%10000007;
        }

        printf("Case %lld: %llu\n", ++caseno, result[n]%10000007);
    }
    return 0;
}
