#include <bits/stdc++.h>
using namespace std;

int t,n,a,b,yes,no;
vector<int>G[1000];
char cmd;
string s;
bool found;
bool visited[1010];

void dfs(int u)
{
    int i,v;
    visited[u]=1;

    for(i=0;i<G[u].size();i++)
    {
        if(G[u][i] == b && !visited[G[u][i]])
        {
            yes++;
            visited[G[u][i]] = true;
            found = true;
            return;
        }
        else
        {
            if(!visited[G[u][i]]) dfs(G[u][i]);
        }
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    cin >> t;

    for(int cs=1; cs<=t; cs++)
    {
        cin >> n; cin.ignore();

        memset(G,0,sizeof(G));
        yes = no = 0;

        while(1)
        {
            if(!getline(cin,s) || s.empty()) break;
            sscanf(s.c_str(),"%c %d %d",&cmd,&a,&b);
            found = false;
            memset(visited,false,sizeof(visited));

            if(cmd == 'c')
            {
                G[a].push_back(b);
                G[b].push_back(a);
            }
            else
            {
                if(a == b) yes++;

                else
                {
                    dfs(a);
                    if(!found) no++;
                }
            }
        }
        cout << yes << "," << no;
        if(cs < t) cout << endl<<endl;
        else cout << endl;
    }

    return 0;
}
