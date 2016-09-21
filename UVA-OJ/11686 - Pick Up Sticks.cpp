#include <bits/stdc++.h>
using namespace std;

#define read(num1,num2) scanf("%d %d", &num1, &num2)

vector<int>g[1000001], toposort;
int visited[1000001];
bool cycle;

void dfs(int u)
{
    visited[u] = 2;
    for(int i=0; i<g[u].size(); i++)
    {
        int p = g[u][i];

        if(visited[p] == 0)
        {
            dfs(p);
            if(cycle)return;
        }
        else if(visited[p] == 2)
        {
            cycle = true; return;
        }
    }
    visited[u] = 1;
    toposort.push_back(u);
}

int main()
{
    freopen("input/in.txt", "r", stdin);
    freopen("input/out.txt", "w", stdout);

    int n,m,a,b;
    while(read(n,m)!=EOF)
    {
        if(n==0 && m==0) break;

        for(int i=1; i<=m; i++)
        {
            read(a,b);
            g[a].push_back(b);
        }

        memset(visited,0,sizeof visited);


        for(int i=1; i<=n; i++)
        {
            if(visited[i] == 0)
            {
                cycle = false;
                dfs(i);
            }
        }
        if(cycle) printf("IMPOSSIBLE\n");
        else
        {
            for(int i=toposort.size()-1; i>=0; i--)
            {
                printf("%d\n", toposort[i]);
            }
        }
        toposort.clear();
        for(int i=1; i<=n; i++) g[i].clear();
    }

    return 0;
}
