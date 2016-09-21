#include <bits/stdc++.h>
using namespace std;

#define read(num) scanf("%d", &num)

vector<int>g[105], topsort;
int visited[105], cnt;
int start, finish;

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



int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int n,m,u,v;

    while(scanf("%d%d", &n,&m))
    {
        if(n == 0 && m==0) break;

        for(int i=1; i<=m; i++)
        {
            read(u); read(v);
            g[u].push_back(v);
        }


        memset(visited, 0, sizeof (visited));

        for(int i=1; i<=n; i++)
        {
            if(!visited[i])
            {
                dfs(i);
            }
        }
        printf("%d", topsort[topsort.size() - 1]);
        for(int i=topsort.size()-2; i>=0; i--)
        {
            printf(" %d", topsort[i]);
        }
        printf("\n");


        topsort.clear();
        for(int i = 1; i <= n; i++) g[i].clear();

    }

    return 0;
}
