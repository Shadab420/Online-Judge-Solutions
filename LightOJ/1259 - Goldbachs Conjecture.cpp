#include <bits/stdc++.h>
using namespace std;

#define read(num) scanf("%d", &num)

int prime[10000000/32];
int primes[664580], primeId;

bool check(int ind, int pos) { return (ind & (1<<pos)); }
int setBit(int ind, int pos) { return (ind |= (1<<pos)); }

void sieve()
{
    primeId=0;
    int last;
    for(int p=2; p<=3162; p++)
    {
        if(check(prime[p>>5], p&31) == 0)
        {
            primes[primeId] = p; primeId++; last = p;
            for(int i=p+p; i <= 10000000; i+=p) prime[i>>5] = setBit(prime[i>>5], i&31);
        }
    }

    for(int p=last+1; p<=10000000/2; p++)
    {
        if(check(prime[p>>5], p&31) ==0)
        {
            primes[primeId] = p;
            primeId++;
        }
    }
}

int main()
{
    freopen("input/in.txt", "r", stdin);
    freopen("input/out.txt", "w", stdout);
    sieve();
    //for(int i=0; i<=10; i++) cout << primes[i] << endl;
    //cout << primeId << endl;

    int t, n, cnt; read(t);
    for(int cs=1; cs<=t; cs++)
    {
        read(n);
        map<pair<int,int>,int>taken;
        int cnt=0;
        for(int i=0; i<primeId; i++)
        {
            int p1 = primes[i];
            if(p1 <= n)
            {
                int p2 = n-p1;
                if(check(prime[p2>>5], p2&31) == 0 && p1 <= p2) cnt++;
            }
        }
        printf("Case %d: %d\n", cs, cnt);
    }

    return 0;
}
