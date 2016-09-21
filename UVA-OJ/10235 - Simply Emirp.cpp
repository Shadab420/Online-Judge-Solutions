#include <bits/stdc++.h>
using namespace std;

#define read(num) scanf("%d", &num)

bool prime[1000001];
long long int t,n;

void sieve()
{

    memset(prime,true,sizeof prime);

    for(int i=2; i<=1000; i++)
    {
        if(prime[i])
        {
            for(int j=i+i; j<=1000000; j+=i) prime[j] = false;
        }
    }
}

int main()
{
    freopen("input/in.txt", "r", stdin);
    freopen("input/out.txt", "w", stdout);
    sieve();
    int n,ncpy,revn,noOfDigits,mul;
    while(read(n)!=EOF)
    {
        if(!prime[n]) {printf("%d is not prime.\n", n); continue;}
        ncpy = n;
        noOfDigits = (n==0)?1:floor(log10(n))+1;
        revn=0;

        for(int i=1; i<=noOfDigits; i++)
        {
            revn+=n%10;
            if(i<noOfDigits) revn*=10;
            n/=10;
        }

        if(prime[revn] && ncpy!=revn) printf("%d is emirp.\n", ncpy);
        else printf("%d is prime.\n", ncpy);

    }

    return 0;
}
