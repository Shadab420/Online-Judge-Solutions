#include <bits/stdc++.h>
using namespace std;

#define read(num) scanf("%d", &num)

struct Edge
{
    int u;
    int v;
    int cost;
    bool operator < (const Edge& edg) const { return cost < edg.cost;}
};

Edge edges[55];
map<string,int>m1;
int ctParent[55];

int findd(int x)
{
    if(ctParent[x] == x) return x;
    else return ctParent[x] = findd(ctParent[x]);
}

int kruskal(int noOfRoads, int noOfCities)
{
    sort(edges,edges+noOfRoads);
    for(int i=1; i<=noOfCities; i++) ctParent[i] = i;
    int cntRoads=0, totalCost=0;
    for(int i=0; i<noOfRoads; i++)
    {
        int u = findd(edges[i].u);
        int v = findd(edges[i].v);
        if(u!=v)
        {
            ctParent[u] = v;
            cntRoads++;
            totalCost+=edges[i].cost;
            if(cntRoads == noOfCities-1) break;
        }
    }
    if(cntRoads < noOfCities-1) return -1;
    else return totalCost;
}

int main()
{
    freopen("input/in.txt","r",stdin);
    freopen("input/out.txt","w",stdout);
    int t,m,c; read(t);
    string c1,c2;

    for(int cs=1; cs<=t; cs++)
    {
        read(m);
        int ctid=1, edgeId=0;
        bool exist1, exist2, found;
        Edge e;

        for(int i=0; i<m; i++)
        {
            cin >> c1 >> c2 >> c;
            if(m1[c1] == 0) { m1[c1] = ctid; ctid++; exist1 = false;}
            else exist1 = true;

            if(m1[c2] == 0) {m1[c2] = ctid; ctid++; exist2 = false;}
            else exist2 = true;

            int ct1 = m1[c1], ct2 = m1[c2];
            e.u = ct1;
            e.v = ct2;
            e.cost = c;

            if(exist1 && exist2)
            {
                found = false;
                for(int j=0; j<edgeId; j++)
                {
                    if(edges[j].u == ct1 && edges[j].v == ct2 )
                    {
                        found = true;
                        if(edges[j].cost > c) edges[j].cost = c;
                    }
                }
            }
            if(!found || (!exist1 || !exist2))
            {
                edges[edgeId] = e;
                edgeId++;
            }
        }
        int ans = kruskal(edgeId,ctid-1);
        if(ans == -1) printf("Case %d: Impossible\n", cs);
        else printf("Case %d: %d\n", cs,ans);
        m1.clear();
    }

    return 0;
}
