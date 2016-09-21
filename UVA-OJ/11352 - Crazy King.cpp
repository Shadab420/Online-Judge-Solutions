#include <bits/stdc++.h>
using namespace std;

#define read(num) scanf("%d", &num)
int t,m,n,Ax,Ay,Bx,By;
int g[101][101];
int dist[101][101];
int kingx[] = {0,0,1,-1,1,1,-1,-1};
int kingy[] = {1,-1,0,0,-1,1,-1,1};
int knightx[] = {1,1,-1,-1,2,2,-2,-2};
int knighty[] = {-2,2,-2,2,-1,1,-1,1};

void bfs(int x, int y)
{
        queue<pair<int,int>>bfsq;
        bfsq.push(make_pair(x,y));
       for(int i=0; i<101; i++)
       {
               for(int j=0; j<101; j++) dist[i][j] = 1000000;
       }
        dist[x][y] = 0;

        while(!bfsq.empty())
        {
                int currx = bfsq.front().first;
                int curry = bfsq.front().second;
                bfsq.pop();

                for(int i=0; i<8; i++)
                {
                        int nx,ny;
                        nx = currx+kingx[i];
                        ny = curry+kingy[i];

                        if(nx>=0 && nx<m && ny>=0 && ny<n && g[nx][ny]==0 && dist[nx][ny] > dist[currx][curry]+1)
                        {
                                dist[nx][ny] = dist[currx][curry]+1;
                                bfsq.push(make_pair(nx,ny));
                        }
                }
        }
}

int main()
{
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
        read(t);

        for(int cs=1; cs<=t; cs++)
        {
                read(m); read(n);
                char graph[101][101];
                for(int i=0; i<m; i++)
                {
                        cin >> graph[i];
                }

                 /*for(int i=0; i<m; i++)
                {
                        for(int j=0; j<n; j++)
                        {
                                cout << graph[i][j] << " ";
                        }
                        cout << endl;
                }*/

                for(int i=0; i<m; i++)
                {
                        for(int j=0; j<n; j++)
                        {

                                if(graph[i][j] == 'A')
                                {
                                        Ax=i; Ay =j;
                                }
                                else if(graph[i][j] == 'B')
                                {
                                        Bx = i; By = j;
                                }
                                else if(graph[i][j] == 'Z')
                                {
                                        g[i][j] = 3;

                                        for(int a=0; a<8; a++)
                                        {
                                                int nx = i+knightx[a];
                                                int ny = j+knighty[a];
                                                if(nx>=0 && nx<m && ny>=0 && ny<n && graph[nx][ny] != 'A' && graph[nx][ny] != 'B') g[nx][ny] = 3;
                                        }
                                }
                        }
                }

                /*for(int i=0; i<m; i++)
                {
                        for(int j=0; j<n; j++)
                        {
                                cout << g[i][j] << " ";
                        }
                        cout << endl;
                }*/

                bfs(Ax,Ay);

                if(dist[Bx][By] == 1000000) printf("King Peter, you can't go now!\n");
                else printf("Minimal possible length of a trip is %d\n", dist[Bx][By]);
                memset(g,0,sizeof g);
        }

        return 0;
}
