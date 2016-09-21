#include <bits/stdc++.h>
using namespace std;

#define read(num) scanf("%d", &num)

struct data
{
    int node, cost;
    data(int a, int b) {node = a; cost = b;}
};

int t,n,m,x,y,timee;
vector<data>g[1001];
int dist[1001];

void bellmanFordShortestPath(int source)
{
    dist[source] = 0;

    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n; j++)
        {
            for(int k=0; k<g[j].size(); k++)
            {
                int v = g[j][k].node;
                int costt = g[j][k].cost;
                if(dist[j]+costt < dist[v])
                {
                    dist[v] = dist[j]+costt;
                }
            }
        }
    }

    for(int j=0; j<n; j++)
    {
        for(int k=0; k<g[j].size(); k++)
        {
            int v = g[j][k].node;
            int costt = g[j][k].cost;
            if(dist[j]+costt < dist[v])
            {
                printf("possible\n"); return;
            }
        }
    }
    printf("not possible\n");
}

int main()
{
    freopen("input/in.txt","r",stdin);
    freopen("input/out.txt","w",stdout);
    read(t);

    for(int cs=1; cs<=t; cs++)
    {
        read(n); read(m);

        for(int i=0; i<1001; i++)
        {
            dist[i] = 1000000000; g[i].clear();
        }

        for(int i=0; i<m; i++)
        {
            read(x); read(y); read(timee);
            data d(y,timee);
            g[x].push_back(d);
        }

        bellmanFordShortestPath(0);
    }

    return 0;
}
