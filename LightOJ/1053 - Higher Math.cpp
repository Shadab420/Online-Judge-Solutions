#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int a,b,c,t,i; scanf("%lld",&t);

    for(i=1; i<=t; i++)
    {
        scanf("%lld %lld %lld", &a,&b,&c);
        printf("Case %lld: ", i);
        if(a*a+b*b == c*c || a*a+c*c == b*b || b*b+c*c == a*a) printf("yes\n");
        else printf("no\n");
    }

    return 0;
}
