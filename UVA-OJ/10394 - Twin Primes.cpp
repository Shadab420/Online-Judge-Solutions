#include <bits/stdc++.h>
using namespace std;

#define read(num) scanf("%d", &num)

bool prime[20000001];
map<int,pair<int,int>>twinPrimes;

void sieve()
{
    memset(prime,true,sizeof prime);

    for(int p=2; p*p < 20000001; p++)
    {
        if(prime[p])
        {
            for(int i=p+p; i<20000001; i+=p) prime[i] = false;
        }
    }
    int id = 1;
    for(int i=2; i<20000001; i++)
    {
        if(prime[i] && prime[i+2])
        {
            twinPrimes[id] = make_pair(i,i+2);
            id++;
        }
    }
}

int main()
{
    freopen("input/in.txt","r",stdin);
    freopen("input/out.txt","w",stdout);
    int n;
    sieve();

    while(read(n) != EOF)
    {
        printf("(%d, %d)\n", twinPrimes[n].first, twinPrimes[n].second);
    }

    return 0;
}
