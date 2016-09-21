#include <bits/stdc++.h>
using namespace std;

#define read(n1,n2) scanf("%d %d", &n1, &n2)

int r,c;
char grid[101][101];
int dx[8] = {0,0,-1,-1,-1,1,1,1};
int dy[8] = {-1,1,-1,0,1,-1,0,1};

int dfs()
{
    int cnt=0;
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(grid[i][j] == '*')
            {
                bool star = false;

                for(int k=0; k<8; k++)
                {
                    if(i+dx[k] >= 0 && i+dx[k] < r && j+dy[k] >= 0 && j+dy[k] < c)
                    {
                            char get = grid[i+dx[k]][j+dy[k]];
                            if(get == '*') { star = true; break;}
                    }
                }
                if(!star) cnt++;
            }
        }
    }
    return cnt;
}


int main()
{
    freopen("input/in.txt", "r", stdin);
    freopen("input/out.txt", "w", stdout);

    while(read(r,c)!=EOF)
    {
        if(r == 0 && c==0) break;

        for(int i=0; i<r; i++) scanf("%s", &grid[i]);
        cout << dfs() << endl;
    }

    return 0;
}
