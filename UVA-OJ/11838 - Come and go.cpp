#include <bits/stdc++.h>
using namespace std;

vector<int>g[2001], revg[2001], topsort;
int visited[2001];

void dfs(int u)
{
    visited[u] = 1;
    for(int i=0; i<g[u].size(); i++)
    {
        if(!visited[g[u][i]])
        {
            dfs(g[u][i]);
        }
    }
    topsort.push_back(u);
}

void dfs2(int u)
{
    visited[u] = 1;
    for(int i=0; i<revg[u].size(); i++)
    {
        if(!visited[revg[u][i]])
        {
            dfs2(revg[u][i]);
        }
    }
}

int main()
{
    freopen("input/in.txt","r",stdin);
    freopen("input/out.txt","w",stdout);
    int n,m,v,w,p;

    while(scanf("%d%d", &n,&m))
    {
        if(n==0 && m==0) break;

        for(int i=1; i<=m; i++)
        {
            scanf("%d%d%d", &v,&w,&p);

            if(p==1)
            {
                g[v].push_back(w);
                revg[w].push_back(v);
            }
            else
            {
                g[v].push_back(w);
                revg[w].push_back(v);
                g[w].push_back(v);
                revg[v].push_back(w);
            }
        }

        memset(visited,0,sizeof visited);
        for(int i=1; i<=n; i++)
        {
            if(!visited[i]) dfs(i);
        }

        memset(visited,0,sizeof visited);
        int cnt = 0;
        for(int i=topsort.size()-1; i>=0; i--)
        {
            if(!visited[topsort[i]])
            {
                dfs2(topsort[i]);
                cnt++;
            }
        }
        if(cnt == 1) printf("1\n");
        else printf("0\n");

        for(int i=1; i<=n; i++)
        {
            g[i].clear(); revg[i].clear();
        }
        topsort.clear();
    }

    return 0;
}
