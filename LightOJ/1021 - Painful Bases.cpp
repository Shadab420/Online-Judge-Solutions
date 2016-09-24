#include <bits/stdc++.h>
using namespace std;

#define read(num) scanf("%d", &num)

int base, k, noOfDigits;
long long int dp[1<<17][20];
char num[17];

long long int solve(int mask, int mod)
{
    if(__builtin_popcount(mask) == noOfDigits)
    {
        if(mod == 0) return 1;
        else return 0;
    }

    if(dp[mask][mod] != -1) return dp[mask][mod];

    dp[mask][mod] = 0;

    int currDigit;
    for(int i=0; i<noOfDigits; i++)
    {
        if(!(mask & (1<<i)))
        {
            if(isalpha(num[i])) currDigit = 10 + num[i] - 'A';
            else currDigit = num[i] - '0';

            dp[mask][mod] += solve((mask | (1<<i)), ((mod*base)+currDigit)%k);
        }
    }
    return dp[mask][mod];
}

int main()
{
    freopen("input/in.txt","r",stdin);
    freopen("input/out.txt","w",stdout);
    int t; read(t);

    for(int cs=1; cs<=t; cs++)
    {
        read(base); read(k);
        scanf("%s", num);
        noOfDigits = strlen(num);

        memset(dp, -1, sizeof dp);
        printf("Case %d: %lld\n", cs, solve(0,0));
    }

    return 0;
}
