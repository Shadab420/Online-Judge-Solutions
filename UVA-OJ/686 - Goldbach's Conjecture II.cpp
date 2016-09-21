#include <bits/stdc++.h>
using namespace std;

#define read(num) scanf("%d", &num)

bool prime[32768];

void sieve()
{
    memset(prime, true, sizeof prime);

    for(int p=2; p*p<32768; p++)
    {
        if(prime[p])
        {
            for(int i=p+p; i < 32768; i+=p) prime[i] = false;
        }
    }
}

int main()
{
    sieve();
    int n;
    while(read(n)!=EOF)
    {
        if(n == 0) break;
        int cnt = 0;
        int j=n-1;

        for(int i=2; i<=j;)
        {
            if(i+j > n) j--;
            else if(i+j < n) i++;
            else if(i+j == n)
            {
                if(prime[i] && prime[j])
                {
                    cnt++;
                }
                j--;
            }
        }
        printf("%d\n", cnt);
    }

    return 0;
}
