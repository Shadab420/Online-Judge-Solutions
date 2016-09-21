#include <bits/stdc++.h>
using namespace std;

#define read(num) scanf("%d", &num)
#define printcase(cs) printf("Case %d: ", cs);

struct Connection
{
    int schl1, schl2,cost;
    bool operator < (Connection& con) const
    {
        return cost < con.cost;
    }
};

vector<Connection>connections, mst1;
int parent[101];

int findd(int x)
{
    if(parent[x] == x) return x;
    else return parent[x] = findd(parent[x]);
}

int kruskal(int noOfSchools, int ind) //ind is mst1 er edge gular index.
{
    for(int i=1; i<=noOfSchools; i++) parent[i] = i;

    int sz = connections.size();
    int cntEdges=0,cost=0;
    for(int i=0; i<sz; i++)
    {
        if(ind > -1)
        {
            if(mst1[ind].schl1 == connections[i].schl1 && mst1[ind].schl2 == connections[i].schl2) continue;
        }
        int par1 = findd(connections[i].schl1);
        int par2 = findd(connections[i].schl2);
        int currCost = connections[i].cost;

        if(par1 != par2)
        {
            parent[par1] = par2;
            if(ind == -1) mst1.push_back(connections[i]); //first mst hole edge gula track korchi.
            cost+=currCost;
            cntEdges++;
        }
        if(cntEdges == noOfSchools-1) break;
    }
    return cost;
}

int main()
{
    freopen("input/in.txt","r",stdin);
    freopen("input/out.txt","w",stdout);
    int t,numOfschls, numOfConns; read(t);
    Connection conn;

    for(int cs=1; cs<=t; cs++)
    {
        read(numOfschls); read(numOfConns);
        int mst = 0, s1,s2;
        for(int i=0; i<numOfConns; i++)
        {
            read(conn.schl1); read(conn.schl2); read(conn.cost);
            connections.push_back(conn);
        }
        sort(connections.begin(), connections.end());

        s1 = kruskal(numOfschls, -1); mst = 1;

        s2 = INT_MAX;
        for(int i=0; i<mst1.size(); i++)
        {
            int temp = kruskal(numOfschls,i);
            if(temp >= s1) s2 = min(s2,temp);
        }

        printf("%d %d\n", s1,s2);
        connections.clear(); mst1.clear();
    }

    return 0;
}
