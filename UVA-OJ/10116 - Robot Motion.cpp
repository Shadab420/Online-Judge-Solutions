#include <bits/stdc++.h>
using namespace std;

struct Group
{
    int rIndex;
    int cIndex;
};


int row,col,start,cnt,beforeLoop;
char g[12][12];
bool visited[12][12];
vector<Group>group;
bool foundLoop;

void dfs(int r, int c)
{
    visited[r][c] = true;
    cnt++;

    Group gp;
    gp.rIndex = r; gp.cIndex = c;
    group.push_back(gp);

    if(g[r][c] == 'N')
    {
        if(r-1>=1 && !visited[r-1][c])
        {
            dfs(r-1,c);
        }
        else if(visited[r-1][c])
        {
            foundLoop = true;
            for(int i=0; i<group.size(); i++)
            {
                if(group[i].rIndex != r-1 || group[i].cIndex != c) beforeLoop++;
                else return;
            }
        }
    }
    else if(g[r][c] == 'S')
    {
        if(r+1 <= row && !visited[r+1][c])
        {
            dfs(r+1,c);
        }
        else if(visited[r+1][c])
        {
            foundLoop = true;
            for(int i=0; i<group.size(); i++)
            {
                if(group[i].rIndex != r+1 || group[i].cIndex != c) beforeLoop++;
                else return;
            }
        }
    }
    else if(g[r][c] == 'E')
    {
        if(c+1 <= col && !visited[r][c+1])
        {
            dfs(r,c+1);
        }
        else if(visited[r][c+1])
        {
            foundLoop = true;
            for(int i=0; i<group.size(); i++)
            {
                if(group[i].rIndex != r || group[i].cIndex != c+1) beforeLoop++;
                else return;
            }
        }
    }
    else if(g[r][c] == 'W')
    {
        if(c-1>=1 && !visited[r][c-1])
        {
            dfs(r,c-1);
        }
        else if(visited[r][c-1])
        {
            foundLoop = true;
            for(int i=0; i<group.size(); i++)
            {
                if(group[i].rIndex != r || group[i].cIndex != c-1) beforeLoop++;
                else return;
            }
        }
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    while(cin >> row >> col >> start && row>0 && col>0 && start > 0)
    {
        for(int i=1; i<=row; i++)
        {
            for(int j=1; j<=col; j++)
            {
                cin >> g[i][j];
            }
        }

        memset(visited,false,sizeof visited);
        cnt = beforeLoop = 0;
        foundLoop = false;
        dfs(1,start);

        if(foundLoop)
        {
            cout << beforeLoop << " step(s) before a loop of " << cnt - beforeLoop << " step(s)\n";
        }
        else cout << cnt << " step(s) to exit\n";

        memset(g,'\0',sizeof g);

        group.clear();
    }

    return 0;
}
