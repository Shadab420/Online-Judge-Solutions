#include <bits/stdc++.h>
using namespace std;

#define read(num) scanf("%d", &num)

vector<int>g[100001];
int visited[100001];
vector<int>toposort;

void topsort(int u)
{
    visited[u] = 1;
    for(int i=0; i<g[u].size(); i++)
    {
        if(!visited[g[u][i]]) topsort(g[u][i]);
    }
    toposort.push_back(u);
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
    int t,n,e,a,b; read(t);

    for(int cs=1; cs<=t; cs++)
    {
        read(n); read(e);

        for(int i=1; i<=e; i++)
        {
            read(a); read(b);
            g[a].push_back(b);
        }

        memset(visited,0,sizeof(visited));
        for(int i=1; i<=n; i++)
        {
            if(!visited[i]) topsort(i);
        }

        memset(visited,0,sizeof(visited));
        int cnt = 0;
        for(int i=n-1; i>=0; i--)
        {
            if(!visited[toposort[i]])
            {
                cnt++; dfs(toposort[i]);
            }
        }
        cout << cnt << endl;

        for(int i=0; i<100001; i++) g[i].clear();
        toposort.clear();
    }

    return 0;
}


