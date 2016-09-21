#include <bits/stdc++.h>
using namespace std;

int coins[21];
long long int dp[10000];

void countWays()
{
    dp[0] = 1;

    long long int val1 = 0, val2 = 0;

    for(int i=1; i<=21; i++)
    {
        for(int j=coins[i]; j<10000; j++)
        {
            if(j-coins[i] >= 0)
            {
                val1 = dp[j-coins[i]];
                val2 = dp[j];
                dp[j] = val1 + val2;
            }
            else break;

        }
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int n;
    for(int i=1; i<=21; i++)
    {
        coins[i] = i*i*i;
    }

    countWays();


    while(cin >> n)
    {
        cout << dp[n] << endl;
    }

    return 0;
}
