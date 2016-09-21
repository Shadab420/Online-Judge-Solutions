#include <bits/stdc++.h>
using namespace std;

char grid[100][100];
bool visited[100][100];
int m,n,cnt,oildeposits;

void dfs(int x, int y)
{
    visited[x][y] = true;

    cnt++;

    if(x-1>=0 && grid[x-1][y] == '@' && !visited[x-1][y]) dfs(x-1,y);
    if(x-1>=0 && y-1 >= 0 && grid[x-1][y-1] == '@' && !visited[x-1][y-1]) dfs(x-1,y-1);
    if(x-1>=0 && y+1<=n-1 && grid[x-1][y+1] == '@' && !visited[x-1][y+1]) dfs(x-1,y+1);
    if(y-1>=0 && grid[x][y-1] == '@' && !visited[x][y-1]) dfs(x,y-1);
    if(y+1<=n-1 && grid[x][y+1] == '@' && !visited[x][y+1]) dfs(x,y+1);
    if(x+1<=m-1 && grid[x+1][y] == '@' && !visited[x+1][y]) dfs(x+1,y);
    if(x+1<=m-1 && y-1>=0 && grid[x+1][y-1] == '@' && !visited[x+1][y-1]) dfs(x+1,y-1);
    if(x+1>=0 && y+1<=n-1 && grid[x+1][y+1] == '@' && !visited[x+1][y+1]) dfs(x+1,y+1);
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int cs = 0;

    while(cin >> m >> n)
    {
        if(m == 0 && n==0) break;
        cs++;

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin >> grid[i][j];
            }
        }

        memset(visited,false,sizeof visited);
        oildeposits = 0;

        cnt = 0;

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                //cout << grid[i][j];
                if(!visited[i][j] && grid[i][j] == '@')
                {

                    dfs(i,j);

                    if(cnt > 0)
                    {
                        //cout << "Case " << cs << ": " << cnt << endl;
                        oildeposits++;
                        cnt = 0;
                    }
                }
            }
            //cout << endl;
        }
        cout << oildeposits << endl;
        memset(grid,'\0',sizeof grid);
    }

    return 0;
}
