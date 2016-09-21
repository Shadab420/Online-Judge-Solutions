#include <bits/stdc++.h>
using namespace std;

#define read(num) scanf("%d", &num)
int t,n,m,arr[10001];
int dp[10001][105];

int solve(int pos, int sum)
{
    if(pos == n)
    {
        if(sum%m==0) return 1;
        else return 0;
    }
    int mod = sum%m;
    if(dp[pos][mod] == -1)
    {
        bool ans1 = solve(pos+1,abs(sum+arr[pos]));
        if(ans1)
        {
            dp[pos][mod] = ans1;
            return ans1;
        }
        bool ans2 = solve(pos+1, abs(sum-arr[pos]));
        dp[pos][mod] = ans2;
    }
    return dp[pos][mod];
}

int main()
{
    freopen("input/in.txt","r",stdin);
    freopen("input/out.txt","w",stdout);
    read(t);

    for(int cs=1; cs<=t; cs++)
    {
        read(n); read(m);
        for(int i=0; i<n; i++) read(arr[i]);
        memset(dp,-1,sizeof(dp));
        if(solve(0,0)) printf("Divisible\n");
        else printf("Not divisible\n");
    }

    return 0;
}
