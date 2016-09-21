#include <bits/stdc++.h>
using namespace std;

#define read(num) scanf("%d", &num)

struct data
{
    int node;
    int costt;
    data(int a, int b)
    {
        node = a; costt = b;
    }

    bool operator < (const data& p) const
    {
        return p.costt < costt;
    }
};

vector<int>g[20001];
vector<int>cost[20001];
int dist[20001];

int dijkstra(int source, int dest)
{
    priority_queue<data>q;
    for(int i=0; i<20001; i++) dist[i] = 1000000000;
    dist[source] = 0;
    data d(source,0);
    q.push(d);

    while(!q.empty())
    {
        data u = q.top(); q.pop();

        if(u.node == dest) return dist[dest];

        for(int i=0; i<g[u.node].size(); i++)
        {
            int v = g[u.node][i];
            int costt = cost[u.node][i];

            if(dist[u.node] + costt < dist[v])
            {
                dist[v] = dist[u.node] + costt;

                data temp(v,dist[v]);
                q.push(temp);
            }
        }
    }

    return dist[dest];
}

int main()
{
    freopen("input/in.txt","r",stdin);
    freopen("input/out.txt","w",stdout);
    int t,n,m,source,target,a,b,w; read(t);

    for(int cs=1; cs<=t; cs++)
    {
        read(n); read(m); read(source); read(target);

        for(int i=1; i<=m; i++)
        {
            read(a); read(b); read(w);
            g[a].push_back(b);
            g[b].push_back(a);
            cost[a].push_back(w);
            cost[b].push_back(w);
        }

        int res = dijkstra(source, target);
        printf("Case #%d: ", cs);
        if(res == 1000000000) printf("unreachable\n");
        else printf("%d\n", res);

        for(int i=0; i<n; i++)
        {
            g[i].clear();
            cost[i].clear();
        }
    }

    return 0;
}
