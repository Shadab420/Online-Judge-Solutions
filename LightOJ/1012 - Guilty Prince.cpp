#include <bits/stdc++.h>
using namespace std;

int t,w,h,cells;
char grid[20][20];

bool visited[20][20];

void dfs(int x, int y)
{
    visited[x][y] = true;
    cells++;
    if(y+1<w && grid[x][y+1] == '.' && !visited[x][y+1]) dfs(x,y+1);
    if(y-1>=0 && grid[x][y-1] == '.' && !visited[x][y-1]) dfs(x,y-1);
    if(x+1<h && grid[x+1][y] == '.' && !visited[x+1][y]) dfs(x+1,y);
    if(x-1>=0 && grid[x-1][y] == '.' && !visited[x-1][y]) dfs(x-1,y);


}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    cin >> t;

    for(int cs=1; cs<=t; cs++)
    {
        cin >> w >> h;
        int startI, startJ;
        memset(grid,'\0',sizeof(grid));
        for(int i=0; i<h; i++)
        {
            for(int j=0; j<w; j++)
            {
                cin >> grid[i][j];
                if(grid[i][j] == '@')
                {
                    startI = i;
                    startJ = j;
                }

            }
        }

        cells = 0;
        memset(visited,false,sizeof(visited));
        dfs(startI,startJ);

        cout << "Case " << cs << ": " << cells << endl;
    }

    return 0;
}
