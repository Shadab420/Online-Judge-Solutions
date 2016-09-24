#include <bits/stdc++.h>
using namespace std;

int dx[] = {1,1,-1,-1,2,2,-2,-2};
int dy[] = {-2,2,-2,2,-1,1,-1,1};
int dist[8][8];

void bfs(int x, int y)
{
    queue<pair<int,int>>q;
    q.push(make_pair(x,y));

    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            dist[i][j] = 1000000;
        }
    }
    dist[x][y] = 0;

    while(!q.empty())
    {
        int currx = q.front().first;
        int curry = q.front().second;
        q.pop();

        for(int i=0; i<8; i++)
        {
            int nx = currx+dx[i];
            int ny = curry+dy[i];

            if(nx>=0 && nx<8 && ny>=0 && ny<8 && dist[nx][ny] > dist[currx][curry]+1)
            {
                dist[nx][ny] = dist[currx][curry]+1;
                q.push(make_pair(nx,ny));
            }
        }
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    map<char,int>charmap;
    charmap['a'] = 0; charmap['b'] = 1; charmap['c'] = 2; charmap['d'] = 3;
    charmap['e'] = 4; charmap['f'] = 5; charmap['g'] = 6; charmap['h'] = 7;

    char c1, c2;
    int x1,x2;

    //while(scanf("%c%d%c%d", &c1,&x1,&c2,&x2) != EOF)
    while(cin >> c1 >> x1 >> c2 >> x2)
    {
        bfs(charmap[c1],x1-1);

        printf("To get from %c%d to %c%d takes %d knight moves.\n", c1,x1,c2,x2,dist[charmap[c2]][x2-1]);
    }

    return 0;
}
