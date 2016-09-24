#include <bits/stdc++.h>
using namespace std;

#define read(num) scanf("%d", &num)

vector<int>g[27];
int visited[27];
string ans;

void dfs(int u)
{
    visited[u] = 1;
    ans+=((char)(u+'a'));

    for(int i=0; i<g[u].size(); i++)
    {
        if(!visited[g[u][i]]) dfs(g[u][i]);
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t,v,e; read(t);
    char a,b;

    for(int cs=1; cs<=t; cs++)
    {
        if(cs>1) printf("\n");
        read(v); read(e);

        for(int i=0; i<e; i++)
        {
            cin >> a >> b;
            g[a-97].push_back(b-97);
            g[b-97].push_back(a-97);
        }

        printf("Case #%d:\n", cs);
        memset(visited,0,sizeof(visited));
        int cnt = 0;

        for(int i=0; i<v; i++)
        {
            ans = "";
            if(!visited[i])
            {
                dfs(i); cnt++;
                sort(ans.begin(), ans.end());
                for(int a=0; a<ans.length(); a++) printf("%c,", ans[a]);
                printf("\n");
            }
        }
        printf("%d connected components\n", cnt);
        if(cs==t) printf("\n");
        for(int i=0; i<27; i++) g[i].clear();
    }

    return 0;
}
