#include <bits/stdc++.h>
using namespace std;

#define read(num1) scanf("%lld", &num1)

vector<int>primes;
long long int t,n;

void sieve(int range)
{
    bool prime[range+1];
    memset(prime,true,sizeof prime);
    int w = sqrt(range);
    for(int i=2; i <= w; i++)
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

long long int getNumOfDivisors(int range)
{
    long long int cnt,div=1;
    for(int i=0; i<primes.size(); i++)
    {
        if(primes[i] > range) break; // karon range er beshi prime lage na.
        cnt = 0;
        while(n%primes[i]==0)
        {
            cnt++; n/=primes[i]; range = sqrt(n);
        }
        if(cnt > 0) div*=(cnt+1);
    }
    if(n>1) div*=2;

    return div-1; //karon 1 er power ignore korte hobe.
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    read(t);
    sieve(1000000);
    //for(int i=0; i<primes.size(); i++) cout << primes[i] << endl;

    for(int cs=1; cs<=t; cs++)
    {
        read(n);
        int sqrtn = sqrt(n);
        printf("Case %d: %lld\n", cs, getNumOfDivisors(sqrtn));
    }

    return 0;
}
