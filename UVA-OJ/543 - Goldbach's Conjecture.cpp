#include <bits/stdc++.h>
using namespace std;

#define read(num) scanf("%d", &num)

bool prime[1000001];
vector<int>primes;

void sieve()
{
    memset(prime, true, sizeof prime);

    for(int p=2; p*p<1000001; p++)
    {
        if(prime[p])
        {
            for(int i=p+p; i < 1000001; i+=p) prime[i] = false;
        }
    }

    for(int p=2; p<1000001; p++)
    {
        if(prime[p]) primes.push_back(p);
    }
}

int main()
{
    sieve();

    int n;
    while(read(n)!=EOF)
    {
        if(n == 0) break;

        int maxi = -INT_MAX;

        int p1,p2;
        for(int i=0; i<primes.size(); i++)
        {
            if(prime[n-primes[i]])
            {
                 if(abs(primes[i]-(n-primes[i])) > maxi)
                {
                    maxi = abs(primes[i]-(n-primes[i]));
                    p1 = primes[i]; p2 = n-primes[i];
                }
                break;
            }
        }

        printf("%d = %d + %d\n", n,p1,p2);
    }


    return 0;
}
