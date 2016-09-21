#include <bits/stdc++.h>
using namespace std;

int t,n,price[1001], weight[1001],m,capacity,dp[1001][35], ans;

int getMaxCost_TopDown(int i, int w)
{
    if(i == n) return 0;
    if(dp[i][w] != -1) return dp[i][w];

    int profit1 = 0, profit2 = 0;

    if(w+weight[i] <= capacity)
    {
        profit1 = price[i] + getMaxCost_TopDown(i+1, w+weight[i]);
    }
    profit2 = getMaxCost_TopDown(i+1,w);

    dp[i][w] = max(profit1,profit2);

    return dp[i][w];
}

int getMaxCost_BottomUp(int w)
{
    int profit1 = 0, profit2 = 0;

    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=w; j++)
        {
            if(i==0 || j==0) dp[i][j] = 0;

            else if(weight[i-1] <= j)
            {
                profit1 = price[i-1] + dp[i-1][j-weight[i-1]];
                profit2 = dp[i-1][j];
                dp[i][j] = max(profit1,profit2);
            }
            else dp[i][j] = dp[i-1][j];

        }
    }

    return dp[n][w];
}

int main()
{
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    cin >> t;

    for(int cs=1; cs<=t; cs++)
    {
        cin >> n;
        for(int i=0; i<n; i++) cin >> price[i] >> weight[i];

        cin >> m;
        ans =0;

        for(int i=0; i<m; i++)
        {
            cin >> capacity;
            //memset(dp,-1,sizeof dp);
            //ans+=getMaxCost_TopDown(0,0);
            ans+=getMaxCost_BottomUp(capacity);
        }
        cout << ans << endl;
    }

    return 0;
}
