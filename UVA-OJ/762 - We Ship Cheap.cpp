#include <bits/stdc++.h>
using namespace std;

#define read(num) scanf("%d", &num)

vector<int>g[1001];
map<string,int>m1;
map<int,string>m2;
int dist[10001];

void bfs(int start, int endd)
{
    queue<int>bfsq;
    bfsq.push(endd);
    dist[endd] = 0;

    while(!bfsq.empty())
    {
        int u = bfsq.front();
        bfsq.pop();

        for(int i=0; i<g[u].size(); i++)
        {
            int v = g[u][i];
            if(dist[v] == -1)
            {
                dist[v] = u;
                bfsq.push(v);
            }
            if(v == start) return;
        }
    }
}

int main()
{
    freopen("input/in.txt","r",stdin);
    freopen("input/out.txt","w",stdout);

    int n,cs=0;
    string city1, city2, source, dest;

    while(read(n) !=EOF)
    {
        if(cs >= 1) printf("\n"); cs++;

        int id = 1;
        for(int i=0; i<n; i++)
        {
            cin >> city1 >> city2;

            if(m1[city1] == 0) {m1[city1] = id; m2[id] = city1; id++;}
            if(m1[city2] == 0) {m1[city2] = id; m2[id] = city2; id++;}

            g[m1[city1]].push_back(m1[city2]);
            g[m1[city2]].push_back(m1[city1]);

        }

        for(int i=1; i<id; i++) dist[i] = -1;

        cin >> source >> dest;

        bfs(m1[source], m1[dest]);

        if(dist[m1[source]] == -1 ||  m1[source] == 0 || m1[dest] == 0) printf("No route\n");
        else if(source == dest) cout << source << " " << dest << "\n";
        else
        {
            int i = m1[source];

            while(dist[i])
            {
                cout << m2[i] << " " << m2[dist[i]] << "\n";
                i = dist[i];
            }
        }

        for(int i=1; i<id; i++) g[i].clear();
        m1.clear(); m2.clear();
    }

    return 0;
}
