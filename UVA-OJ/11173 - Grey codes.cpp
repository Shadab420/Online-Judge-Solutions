#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,k; scanf("%d",&t);
    for(int cs=1; cs<=t; cs++)
    {
        scanf("%d%d",&n,&k);
        k = k^(k>>1);
        printf("%d\n",k);
    }

    return 0;
}
