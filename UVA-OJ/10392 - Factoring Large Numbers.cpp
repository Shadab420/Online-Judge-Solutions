#include <bits/stdc++.h>
using namespace std;

#define read(num) scanf("%lld", &num)

vector<int>primes;

void sieve(int range)
{
    bool prime[range+1];
    memset(prime,true, sizeof prime);
    int sqrtrange = sqrt(range);

    for(int i=2; i<sqrtrange; i++)
    {
        if(prime[i])
        {
            for(int j=i+i; j<=range; j+=i) prime[j] = false;
        }
    }
    for(int i=2; i<=range; i++)
    {
        if(prime[i]) primes.push_back(i);
    }
}

bool getFactors(long long int n)
{
    int range = sqrt(n);
    for(int i=0; i<primes.size(); i++)
    {
        if(primes[i] > range) break;

        while(n%primes[i] == 0)
        {
            printf("    %d\n", primes[i]);
            n/=primes[i];
            range = sqrt(n);
        }
    }
    if(n>1) printf("    %lld\n", n);
    printf("\n");
}

int main()
{
    freopen("input/in.txt","r",stdin);
    freopen("input/out.txt","w",stdout);
    long long int n;
    sieve(1000000);

    while(read(n) != EOF)
    {
        if(n < 0) break;
        getFactors(n);
    }

    return 0;
}
