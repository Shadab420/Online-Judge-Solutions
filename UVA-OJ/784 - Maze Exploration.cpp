#include <bits/stdc++.h>
using namespace std;

#define read(num) scanf("%d", &num)

int r, c, startx, starty;
char grid[35][85];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

void dfs(int x, int y)
{
    if(x >= 0 && x < r-1 && y >= 0 && y < c)
    {
        grid[x][y] = '#';
        for(int i=0; i<4; i++)
        {
            int newx = x+dx[i], newy = y+dy[i];
            if(newx >=0 && newx < r-1 && newy >= 0 && newy < c && grid[newx][newy] == ' ')
            {
                dfs(newx, newy);
            }
        }
    }
}

int main()
{
    freopen("input/in.txt","r",stdin);
    freopen("input/out.txt","w",stdout);
    int t; read(t); cin.ignore();

    for(int cs=1; cs<=t; cs++)
    {
        r = 0;
        while(gets(grid[r]))
        {
            //printf("%s\n", grid[r]);
            bool found = false;

            for(int i=0; i<strlen(grid[r]); i++)
            {
                if(grid[r][i] == '_') break;
                else if(grid[r][i] == '*') { startx = r; starty = i; found = true; }
                if(found)
                {
                        c = strlen(grid[r]);
                        found = false;
                }
            }
            r++;
            if(grid[r-1][0] == '_') break;
        }

        //cout << r << " " << c << endl;
        //cout << startx << " " << starty << endl;
        dfs(startx, starty);

        for(int i=0; i<r; i++)
        {
           cout << grid[i] << "\n";
        }
    }

    return 0;
}
