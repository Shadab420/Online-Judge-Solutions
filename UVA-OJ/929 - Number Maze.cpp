#include <bits/stdc++.h>
using namespace std;

#define read(num) scanf("%d", &num)

struct data
{
    int nx, ny, cost;

    data(int x, int y, int c) { nx=x; ny=y; cost=c; }

    bool operator < (const data& d) const
    {
        return d.cost < cost;
    }
};

int t,n,m;
int grid[1000][1000], dist[1000][1000];
int dirx[] = {-1,1,0,0};
int diry[] = {0,0,-1,1};

int dijkstra(int sx, int sy, int dx, int dy)
{
    priority_queue<data>q;

    dist[sx][sy] = grid[sx][sy];

    data temp(sx,sy,grid[sx][sy]); q.push(temp);

    while(!q.empty())
    {
        int ux = q.top().nx;
        int uy = q.top().ny;
        int ucost = q.top().cost;
        q.pop();

        if(ux == dx && uy == dy) return dist[dx][dy];

        for(int i=0; i<4; i++)
        {
            int vx = ux+dirx[i];
            int vy = uy+diry[i];

            if(vx>=0 && vx< n && vy>=0 && vy<m)
            {
                if(ucost + grid[vx][vy] < dist[vx][vy])
                {
                    dist[vx][vy] = ucost + grid[vx][vy];
                    data tmp(vx,vy,dist[vx][vy]);
                    q.push(tmp);
                }
            }
        }
    }

    return dist[dx][dy];
}

int main()
{
    freopen("input/in.txt","r",stdin);
    freopen("input/out.txt","w",stdout);

    read(t);

    for(int cs=1; cs<=t; cs++)
    {
        for(int i=0; i<1000; i++)
        {
            for(int j=0; j<1000; j++)
            {
                dist[i][j] = 1000000000; grid[i][j] = 0;
            }
        }

        read(n); read(m);

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                read(grid[i][j]);
            }
        }

        printf("%d\n", dijkstra(0,0,n-1,m-1));
    }

    return 0;
}
