#include <bits/stdc++.h>
using namespace std;

#define read(num) scanf("%d", &num)
#define readll(num) scanf("%lld", &num)
typedef long long int lli;

lli gcd(lli x, lli y)
{
    while(y%x > 0)
    {
        lli temp = x;
        x = y%x;
        y = temp;
    }
    return x;
}

int main()
{
    int t;
    lli x,n,cnt,y,m,c1,c2,clone;
    read(t);
    for(int cs=1; cs<=t; cs++)
    {
        readll(x); readll(n); readll(y); readll(m);
        c1=x; c2 = 0;

        for(int i=1; i<=n; i++)
        {
            if(c1>c2) c2+=c1;
            else c1+=c2;
        }

        if(c1>c2) c1+=y;
        else c2+=y;
        printf("Case %d: %lld\n", cs, gcd(c1,c2));
    }

    return 0;
}
