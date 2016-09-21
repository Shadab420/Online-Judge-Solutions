#include <bits/stdc++.h>
using namespace std;

#define read(num) scanf("%d", &num)

vector<int>cut;
int len,n,c,dp[55][55];

int solve(int start, int endd)
{
    if(endd - start < 2) return 0;
    if(dp[start][endd] != -1) return dp[start][endd];

    int cost1 = 0, cost2 = 0;
    dp[start][endd] = INT_MAX;

    for(int i=start+1; i<endd; i++)
    {
        dp[start][endd] = min(cut[endd]-cut[start] + solve(start,i) + solve(i,endd), dp[start][endd]);
    }
    return dp[start][endd];
}

int main()
{
    while(read(len)!=EOF)
    {
        if(len == 0) break;

        read(n);
        cut.push_back(0);
        for(int i=1; i<=n; i++)
        {
            read(c); cut.push_back(c);
        }
        cut.push_back(len);
        memset(dp,-1,sizeof(dp));
        printf("The minimum cutting is %d.\n", solve(0,n+1));
        cut.clear();
    }

    return 0;
}
