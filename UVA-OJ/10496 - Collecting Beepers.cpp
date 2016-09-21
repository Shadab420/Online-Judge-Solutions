#include <bits/stdc++.h>
using namespace std;

#define read(num) scanf("%d", &num)

int t,row, col, noOfBeepers,startx,starty,beeperX, beeperY;
int dp[1<<11][11], dist[11][11];
map<int, pair<int,int>>mapp;

int solve(int mask, int lastPos)
{
    //noOfBeepers+1 because we have an extra bit for start index.
    if(mask == ((1<<noOfBeepers+1)-1)) return dist[lastPos][0] ;

    if(dp[mask][lastPos] != -1) dp[mask][lastPos];

    dp[mask][lastPos] = 1000000000;

    for(int i=0; i<=noOfBeepers; i++)
    {
        if((mask &(1<<i)) == 0)
        {
            dp[mask][lastPos] = min(dp[mask][lastPos], solve((mask | (1<<i)), i) + dist[lastPos][i]);
        }
    }
    return dp[mask][lastPos];
}

int main()
{
    freopen("input/in.txt","r",stdin);
    freopen("input/out.txt","w",stdout);
    read(t);

    for(int cs=1; cs<=t; cs++)
    {
        read(row); read(col); read(startx); read(starty); read(noOfBeepers);
        mapp[0] = make_pair(startx,starty);

        for(int i=1; i<=noOfBeepers; i++)
        {
            read(beeperX); read(beeperY);
            mapp[i] = make_pair(beeperX, beeperY);
        }

        for(int i=0; i<=noOfBeepers; i++)
        {
            for(int j=0; j<=noOfBeepers; j++)
            {
                dist[i][j] = abs(mapp[i].first - mapp[j].first) + abs(mapp[i].second - mapp[j].second);
            }
        }

        memset(dp, -1, sizeof dp);
        printf("The shortest path has length %d\n", solve(1,0));
        mapp.clear();
    }

    return 0;
}
