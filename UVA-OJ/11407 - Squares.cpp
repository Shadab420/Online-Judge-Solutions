#include <bits/stdc++.h>
using namespace std;

#define read(num) scanf("%d", &num)
int t,n;
int dp[10001];

int solve(int sum)
{
    if(sum == 0)
    {
        return 0;
    }

    if(dp[sum] == -1)
    {
    	dp[sum] = INT_MAX;
    	int val1 = INT_MAX;

	    for(int i=1; i<=n; i++)
	    {
	        if(sum-(i*i) >= 0)
	        {
	            val1 = 1+solve(sum-(i*i));
	            dp[sum] = min(val1, dp[sum]);
	        }
	        else break;
    	}
    }
	return dp[sum];
}

int main()
{
    freopen("input/in.txt", "r", stdin);
    freopen("input/out.txt", "w", stdout);
    read(t);
    memset(dp, -1, sizeof dp);

    for(int cs=1; cs<=t; cs++)
    {
        read(n);
        printf("%d\n", solve(n));
    }

    return 0;
}
