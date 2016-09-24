#include <bits/stdc++.h>
using namespace std;

#define read(num) scanf("%d", &num)

struct target
{
    int node, cost;
    target(int _n, int _cost)
    {
        node = _n; cost = _cost;
    }
};

vector<target>tree[30001];
int visited[30001], currCost, maxCost, farNode;

void dfs(int source, int currCost)
{
    visited[source] = 1;
    for(int i=0; i<tree[source].size(); i++)
    {
        int tar = tree[source][i].node;
        if(!visited[tar])
        {
            int c = tree[source][i].cost;
            dfs(tar,currCost+c);
            if(currCost+c > maxCost)
            {
                maxCost = currCost+c; farNode = tar;
            }
        }
    }
}


int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t,n,u,v,w; read(t);

    for(int cs=1; cs<=t; cs++)
    {
        read(n);
        for(int i=1; i<=n-1; i++)
        {
            read(u); read(v); read(w);
            target tar1(v,w), tar2(u,w);
            tree[u].push_back(tar1);
            tree[v].push_back(tar2);
        }

        memset(visited,0, sizeof(visited));
        currCost = maxCost = 0;
        dfs(0,currCost);
        memset(visited,0, sizeof(visited));
        currCost = maxCost = 0;
        dfs(farNode,currCost);

        printf("Case %d: %d\n", cs, maxCost);

        for(int i=0; i<30001; i++) tree[i].clear();
    }

    return 0;
}
