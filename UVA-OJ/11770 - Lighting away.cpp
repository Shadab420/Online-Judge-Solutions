#include <bits/stdc++.h>
using namespace std;

#define read(num) scanf("%d", &num)

int t,n,m,a,b;
vector<int>g[10001], topsort;
int visited[10001];

void toposort(int u)
{
    visited[u] = 1;
    for(int i=0; i<g[u].size(); i++)
    {
        if(!visited[g[u][i]]) toposort(g[u][i]);
    }
    topsort.push_back(u);
}

void dfs(int u)
{
    visited[u] = 1;
    for(int i=0; i<g[u].size(); i++)
    {
        if(!visited[g[u][i]]) dfs(g[u][i]);
    }
}

int main()
{
    freopen("input/in.txt","r",stdin);
    freopen("input/out.txt","w",stdout);
    int t; read(t);

    for(int cs=1; cs<=t; cs++)
    {
        read(n); read(m);
        for(int i=0; i<m; i++)
        {
            read(a); read(b);
            g[a].push_back(b);
        }

        memset(visited, 0, sizeof visited);

        for(int i=1; i<=n; i++)
        {
            if(!visited[i]) toposort(i);
        }

        memset(visited, 0, sizeof visited);

        int cnt = 0;

        for(int i=topsort.size()-1; i>=0; i--)
        {
            if(!visited[topsort[i]])
            {
                dfs(topsort[i]);
                cnt++;
            }
        }

        printf("Case %d: %d\n", cs, cnt);
        topsort.clear();
        for(int i=1; i<=n; i++) g[i].clear();
    }

    return 0;
}
