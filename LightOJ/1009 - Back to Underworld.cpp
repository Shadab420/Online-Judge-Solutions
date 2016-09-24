#include <bits/stdc++.h>
using namespace std;

vector<int>g[20005];
vector<int>node;
map<int,char>m;

int taken[20005], cV, cL, total;
bool visited[20005];

void dfs(int u)
{
    visited[u] = true;
    if(m[u] == 'v') cV++;
    else cL++;

    for(int i=0; i<g[u].size(); i++)
    {
        if(!visited[g[u][i]])
        {
            dfs(g[u][i]);
        }
    }
}

int main()
{
    int t,n,u,v; cin >> t;

    for(int cs=1; cs<=t; cs++)
    {
        cin >> n;

        bool vampire = true;
        vector<int>empt[20005];
        swap(g,empt);
        node.clear();
        m.clear();
        memset(taken,0,sizeof taken);


        for(int i=0; i<n; i++)
        {
            cin >> u >> v;

            g[u].push_back(v);
            g[v].push_back(u);

            if(!taken[u] && !taken[v])
            {
                node.push_back(u);
                taken[u] = 1;
                node.push_back(v);
                taken[v] = 1;
                m.insert(make_pair(u,'v'));
                m.insert(make_pair(v,'l'));
            }

            if(!taken[u] && taken[v])
            {
                node.push_back(u);
                taken[u] = 1;
                if(m[v] == 'v') m.insert(make_pair(u,'l'));
                else m.insert(make_pair(u,'v'));
            }

            else if(taken[u] && !taken[v])
            {
                node.push_back(v);
                taken[v] = 1;
                if(m[u] == 'v') m.insert(make_pair(v,'l'));
                else m.insert(make_pair(v,'v'));
            }
        }

        memset(visited,false,sizeof visited);
        total = 0;

        for(int i=0; i<node.size(); i++)
        {

            cV = cL = 0;
            if(!visited[node[i]])
            {
                dfs(node[i]);
                total+=max(cV,cL);
            }

        }

        cout << "Case " << cs << ": " << total << endl;

    }


    return 0;
}

