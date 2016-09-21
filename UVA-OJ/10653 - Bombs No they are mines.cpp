#include <bits/stdc++.h>
using namespace std;

int r,c,bombRows,bombRowIdx,totalBombs,bombColIdx;
int grid[1001][1001];

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int dis[1001][1001];

void bfs(int x, int y)
{
    queue<pair<int,int>>bfsq;
    bfsq.push(make_pair(x,y));

    for(int i=0; i<1001; i++)
    {
        for(int j=0; j<1001; j++)
        {
            dis[i][j] = 1000000;
        }
    }
    dis[x][y] = 0;

    while(!bfsq.empty())
    {
        int currx = bfsq.front().first;
        int curry = bfsq.front().second;
        bfsq.pop();

        for(int i=0; i<4; i++)
        {
            int nx = currx+dx[i];
            int ny = curry+dy[i];

            if(nx>=0 && nx<r && ny>=0 && ny<c && grid[nx][ny] ==0 && dis[nx][ny] >dis[currx][curry]+1 )
            {
                dis[nx][ny] = dis[currx][curry]+1;
                bfsq.push(make_pair(nx,ny));
            }
        }
    }
}

int main()
{
    while(scanf("%d%d", &r,&c))
    {
        if(r==0 && c==0) break;

        memset(grid,0,sizeof grid);

        scanf("%d", &bombRows);
        for(int i=1; i<=bombRows; i++)
        {
            scanf("%d %d", &bombRowIdx, &totalBombs);
            for(int j=1; j<=totalBombs; j++)
            {
                scanf("%d", &bombColIdx);
                grid[bombRowIdx][bombColIdx] = 3; ///bomb thakle 3.
            }
        }

        int startx,starty, endx,endy;
        scanf("%d%d%d%d", &startx, &starty, &endx, &endy);

        bfs(startx,starty);

        cout << dis[endx][endy] << endl;
    }

    return 0;
}
