#include <bits/stdc++.h>
using namespace std;

int N,K,M;

long long int dp[55][55][55];

long long int solve(int sum, int k, int m)
{
    if(sum>N || k>K) return 0;
    else if(sum == N)
    {
        if(k == K) return 1;
        else return 0;
    }
    else if(dp[sum][k][m] == -1)
    {
        long long int cnt=0;
        for(int i=1; i<=M; i++) cnt += solve(sum+i, k+1, i);
        dp[sum][k][m] = cnt;
    }
    return dp[sum][k][m];
}

int main()
{
    freopen("input/in.txt", "r", stdin);
    freopen("input/out.txt", "w", stdout);

    while(scanf("%d%d%d", &N,&K,&M) != EOF)
    {
        memset(dp,-1,sizeof dp);
        printf("%lld\n",solve(0,0,0));
    }

    return 0;
}
