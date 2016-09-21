#include <bits/stdc++.h>
using namespace std;

bool prime[100001];
int primes[20001];

void sieve()
{
    memset(prime,true,sizeof prime);
    int sqrtn = sqrt(100000);

    for(int i=2; i<=sqrtn; i++)
    {
        if(prime[i])
        {
            for(int j=i+i; j<=100000; j+=i) prime[j] = false;
        }
    }
    int j=0;
    for(int i=2; i<=100000; i++)
    {
        if(prime[i]) primes[j++] = i;
    }
}

int Euler_Phi(int n)
{
    int ncpy = n, sqrtn = sqrt(n);

    for(int i=0; primes[i] <= sqrtn; i++)
    {
        if(n%primes[i] == 0)
        {
            ncpy -= ncpy/primes[i];
            while(n%primes[i] == 0) n/=primes[i];
        }
    }
    if(n>1) ncpy -= ncpy/n;
    return ncpy;
}

int main()
{
    sieve();
    int n;

    while(scanf("%d", &n) != EOF)
    {
        if(n == 0) break;
        else if(n==1) printf("0\n");
        else printf("%d\n", Euler_Phi(n));
    }

    return 0;
}
