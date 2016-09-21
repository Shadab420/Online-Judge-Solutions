#include <bits/stdc++.h>
using namespace std;

int coin [] = { 50, 25, 10, 5, 1 };
long long int dp[7500];

void count ()
{
    dp[0] = 1;
    int val1 = 0, val2 = 0;
    for ( int i = 0; i < 5; i++ )
    {
        for(int j = coin[i]; j < 7500; j++)
        {
            if(j-coin[i] >= 0)
            {
                val1 = dp [j - coin [i]];
                val2 = dp[j];
                dp[j] = val1 + val2;
            }
            else break;
        }
    }
}

int main ()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    count ();
    int n;

    while ( scanf ("%d", &n) != EOF )
    {
        printf("%ld\n", dp[n]);
    }

    return 0;

}
