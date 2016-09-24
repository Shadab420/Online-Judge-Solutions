#include <bits/stdc++.h>
using namespace std;

#define readInt(num) scanf("%d", &num);
#define read2int(num1,num2) scanf("%d%d", &num1, &num2);

vector<int>g[50001];
bool visited[50001], cycle[50001];
int start, maxx, cnt;
bool foundCycle;

void dfs(int u)
{
    visited[u] = true;
    cnt++;

    for(int i=0; i<g[u].size(); i++)
    {
        if(!visited[g[u][i]])
        {
            dfs(g[u][i]);
        }
        else
        {
            cycle[u] = true;
            cycle[g[u][i]] = true;
            foundCycle = true;
            return;
        }
        if(foundCycle)
        {
            cycle[u] = true; return;
        }
    }
}


int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t,n,u,v; readInt(t);

    for(int cs=1; cs<=t; cs++)
    {
        readInt(n);
        for(int i=1; i<=n; i++)
        {
            read2int(u,v);
            g[u].push_back(v);
        }

        maxx = -1;
        memset(cycle,false,sizeof(cycle));

        for(int i=1; i<=n; i++)
        {
            if(!cycle[i])
            {
                    cnt = 0;
                    memset(visited,false,sizeof(visited));
                    foundCycle = false;
                    dfs(i);

                    if(cnt > maxx)
                    {
                        start = i;
                        maxx = cnt;
                    }
                    else if(cnt == maxx)
                    {
                        start = min(start,i);
                    }
            }
        }

        printf("Case %d: %d\n", cs,start);

        for(int i=0; i<n+1; i++) g[i].clear();
    }

    return 0;
}
