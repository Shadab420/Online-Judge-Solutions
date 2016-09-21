#include <bits/stdc++.h>
using namespace std;

#define read(num) scanf("%lld", &num)

vector<int>primes;
long long int largestPrimeDIvisor;

void sieve(int range)
{
    bool prime[range];
    memset(prime,true,sizeof prime);

    int sqrtRange = sqrt(range);

    for(int i=2; i<sqrtRange; i++)
    {
        if(prime[i])
        {
            for(int p=i+i; p<range; p+=i) prime[p] = false;
        }
    }
    for(int i=2; i<=range; i++)
    {
        if(prime[i]) primes.push_back(i);
    }
}

long long int getLargestPrimeDivisor(long long int n)
{
    int cntPrimeFactors = 0, sqrtn = sqrt(n);
    long long int ncpy = n;
    for(int i=0; i<primes.size(); i++)
    {
        if(primes[i] > sqrtn) break;
        if(n%primes[i] == 0) cntPrimeFactors++;

        while(n%primes[i] == 0)
        {
            largestPrimeDIvisor = largestPrimeDIvisor<primes[i]?primes[i]:largestPrimeDIvisor;
            n/=primes[i];
            sqrtn = sqrt(n);
        }
    }
    if(n>1)
    {
        if(n!=ncpy) return n;
        else return -1;
    }

    if(cntPrimeFactors < 2) largestPrimeDIvisor = -1;
    return largestPrimeDIvisor;
}

int main()
{
    freopen("input/in.txt","r",stdin);
    freopen("input/out.txt","w",stdout);
    long long int n;
    sieve(1000000);

    while(read(n) != EOF)
    {
        if(n == 0) break;
        n = abs(n);
        largestPrimeDIvisor = -1;
        printf("%lld\n", getLargestPrimeDivisor(n));
    }

    return 0;
}
