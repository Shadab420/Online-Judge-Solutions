#include <bits/stdc++.h>
using namespace std;

#define read(num1, num2) scanf("%d%d", &num1, &num2)

map<string,int>nameMap;
vector<int>g[1001], rg[1001], topsort;
int visited[1001];

void toposort(int u)
{
    visited[u] = 1;
    for(int i=0; i<g[u].size(); i++)
    {
        if(!visited[g[u][i]]) toposort(g[u][i]);
    }
    topsort.push_back(u);
}

void dfs(int u)
{
    visited[u] = 1;
    for(int i=0; i<rg[u].size(); i++)
    {
        if(!visited[rg[u][i]]) dfs(rg[u][i]);
    }
}

int main()
{
    freopen("input/in.txt","r",stdin);
    freopen("input/out.txt","w",stdout);
    int n,m;
    string name1, name2;

    while(scanf("%d %d", &n, &m))
    {
        if(n==0 && m==0) break;
        cin.ignore();

        for(int i=1; i<=n; i++)
        {
            getline(cin,name1);
            nameMap[name1] = i;
        }
        for(int i=0; i<m; i++)
        {
            getline(cin, name1);
            getline(cin, name2);

            if(name1 != name2)
            {
                int a = nameMap[name1];
                int b = nameMap[name2];

                g[a].push_back(b);
                rg[b].push_back(a);
            }
        }

        memset(visited, 0, sizeof visited);
        for(int i=1; i<=n; i++)
        {
                if(!visited[i]) toposort(i);
        }

        memset(visited, 0, sizeof visited);
        int cnt = 0;
        for(int i = topsort.size()-1; i>=0; i--)
        {
                if(!visited[topsort[i]])
                {
                    //cout << topsort[i] << endl;
                    dfs(topsort[i]);
                    cnt++;
                }
        }
        printf("%d\n", cnt);

        nameMap.clear();
        topsort.clear();
        for(int i=1; i<=n; i++)
        {
            g[i].clear();
            rg[i].clear();
        }
    }

    return 0;
}
