#include <bits/stdc++.h>
using namespace std;

#define read(num) scanf("%d", &num)
#define printcase(cs) printf("Case #%d : ", cs);

struct Edge
{
    int n1, n2,cost, occurance;
    Edge() {occurance=0;}
    bool operator < (Edge& e) const { return cost < e.cost; }
};

vector<Edge>edge, mst1;
int parent[101];
map<pair<pair<int,int>,int>,int>taken;

int findd(int x)
{
    if(parent[x] == x) return x;
    else return parent[x] = findd(parent[x]);
}

int kruskal(int nodes, int ind) //ind is mst1 er edge gular index.
{
    for(int i=1; i<=nodes; i++) parent[i] = i;

    int sz = edge.size();
    int cntEdges=0,cost=0;
    for(int i=0; i<sz; i++)
    {
        if(ind > -1)
        {
            if(mst1[ind].n1 == edge[i].n1 && mst1[ind].n2 == edge[i].n2 && mst1[ind].cost == edge[i].cost && mst1[ind].occurance == edge[i].occurance) continue;
        }
        int par1 = findd(edge[i].n1);
        int par2 = findd(edge[i].n2);
        int currCost = edge[i].cost;

        if(par1 != par2)
        {
            parent[par1] = par2;
            if(ind == -1) mst1.push_back(edge[i]); //first mst hole edge gula track korchi.
            cost+=currCost;
            cntEdges++;
        }
        if(cntEdges == nodes-1) break;
    }
    if(cntEdges < nodes-1) return -1;
    return cost;
}

int main()
{
    freopen("input/in.txt","r",stdin);
    freopen("input/out.txt","w",stdout);
    int t,nodes, edges; read(t);
    Edge edg;

    for(int cs=1; cs<=t; cs++)
    {
        edge.clear(); mst1.clear(); taken.clear();
        read(nodes); read(edges);
        int mst = 0, s1,s2;
        for(int i=0; i<edges; i++)
        {
            read(edg.n1); read(edg.n2); read(edg.cost);
            taken[make_pair(make_pair(edg.n1,edg.n2),edg.cost)]++;
            edg.occurance = taken[make_pair(make_pair(edg.n1,edg.n2),edg.cost)];
            edge.push_back(edg);
        }
        if(edges < nodes-1) { printcase(cs); printf("No way\n"); continue;}
        sort(edge.begin(), edge.end());

        s1 = kruskal(nodes, -1); mst = 1;
        if(s1 == -1) {printcase(cs); printf("No way\n"); continue;}

        s2 = INT_MAX;
        for(int i=0; i<mst1.size(); i++)
        {
            int temp = kruskal(nodes,i);
            if(temp >= s1) s2 = min(s2,temp);
        }
        if(s2 == -1 || s2 == INT_MAX) { printcase(cs); printf("No second way\n");}
        else { printcase(cs); printf("%d\n", s2);}
    }

    return 0;
}
