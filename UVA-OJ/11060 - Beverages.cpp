#include <bits/stdc++.h>
using namespace std;

#define read(num) scanf("%d", &num)

int g[101][101];
map<string,int>nodeMap;
map<int,string>revMap;
map<int,int> indegree;
int visited[101];

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int n,m,cs=0;

    while(read(n) != EOF)
    {
        cs++;
        memset(g,0,sizeof g);
        nodeMap.clear();
        revMap.clear();

        int nodes=0;
        string beverage;


        for(int i=1; i<=n; i++)
        {
            cin >> beverage;
            nodeMap.insert(make_pair(beverage,i));
            revMap.insert(make_pair(i,beverage));
        }

        read(m);
        string b1,b2;
        for(int i=1; i<=m; i++)
        {
            cin >> b1 >> b2;
            if(!g[nodeMap[b1]][nodeMap[b2]]){
                g[nodeMap[b1]][nodeMap[b2]] = 1;
                indegree[nodeMap[b2]]++;
            }
        }

        printf("Case #%d: Dilbert should drink beverages in this order:", cs);

        memset(visited,0,sizeof visited);

        for(int i=1; i<=n; i++)
        {
            if(!visited[i] && indegree[i]==0)
            {
                printf(" %s", revMap[i].c_str());
                visited[i] = 1;
                for(int j=1; j<=n; j++)
                {
                    if(i!=j && g[i][j] == 1)
                    {
                        indegree[j]--;
                    }
                }
                i=0;
            }
        }

        printf(".\n\n");

    }

    return 0;
}
