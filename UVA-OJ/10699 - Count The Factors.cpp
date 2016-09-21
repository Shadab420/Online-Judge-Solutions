#include <bits/stdc++.h>
using namespace std;

#define read(num) scanf("%d", &num)

bool prime[1000001];
vector<int>primes;

void sieve()
{
    memset(prime,true,sizeof prime);
    int lastPrime;
    for(int i=2; i<=1000; i++)
    {
        if(prime[i])
        {
            primes.push_back(i);
            lastPrime = i;
            for(int j=i+i; j<=1000000; j+=i) prime[j] = false;
        }
    }
    for(int i = lastPrime+1; i<=1000000; i++)
    {
        if(prime[i]) primes.push_back(i);
    }
}

int getDiffFactors(int n)
{
    int cnt = 0, srootn = sqrt(n);

    for(int i=0; i<primes.size(); i++)
    {
        if(primes[i] > srootn) break;
        bool div = false;
        while(n%primes[i] == 0)
        {
            n/=primes[i];
            div = true;

        }
        if(div) cnt++;
    }
    if(n>1) cnt++;
    return cnt;
}

int main()
{
    freopen("input/in.txt","r",stdin);
    freopen("input/out.txt","w",stdout);
    sieve();
    int n;
    while(read(n) != EOF)
    {
        if(n==0) break;
        printf("%d : %d\n", n,getDiffFactors(n));
    }

    return 0;
}
