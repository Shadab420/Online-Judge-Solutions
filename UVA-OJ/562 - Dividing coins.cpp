#include <bits/stdc++.h>
using namespace std;

#define read(num) scanf("%d", &num)

int t,m;
int bag[101], sum, half;
int dp[101][25001];

int solve(int pos, int currSum)
{
    if(pos >= m)
    {
        return abs(currSum-(sum - currSum));
    }

    if(dp[pos][currSum] != -1) return dp[pos][currSum];

    int val1 = solve(pos+1,currSum+bag[pos]);
    if(val1 == 0) dp[pos][currSum] = 0;
    else dp[pos][currSum] = min(val1, solve(pos+1, currSum));
    return dp[pos][currSum];
}

int main()
{
    freopen("input/in.txt","r",stdin);
    freopen("input/out.txt","w",stdout);
    read(t);

    for(int cs=1; cs<=t; cs++)
    {
        read(m);
        sum=0;
        for(int i=0; i<m; i++)
        {
            read(bag[i]);
            sum+=bag[i];
        }

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<=sum; j++) dp[i][j] = -1;
        }
        printf("%d\n", solve(0,0));
    }

    return 0;
}
