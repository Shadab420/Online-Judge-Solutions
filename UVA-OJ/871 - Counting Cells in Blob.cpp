#include <bits/stdc++.h>
using namespace std;

vector<string>g;
bool visited[25][25];
string line;
int cnt,maxx;

void dfs(int i, int j)
{
    visited[i][j] = true;
    cnt++;

    if(i-1 >= 0 && g[i-1][j] == '1' && !visited[i-1][j]) dfs(i-1,j);

    if(i+1 < g.size() && g[i+1][j] == '1' && !visited[i+1][j]) dfs(i+1,j);

    if(j-1 >= 0 && g[i][j-1] == '1' && !visited[i][j-1]) dfs(i,j-1);

    if(j+1 < g[i].length() && g[i][j+1] == '1' && !visited[i][j+1]) dfs(i,j+1);

    if(i-1>=0 && j-1>=0 && g[i-1][j-1] == '1' && !visited[i-1][j-1]) dfs(i-1,j-1);

    if(i-1>=0 && j+1<g[i].length() && g[i-1][j+1] == '1' && !visited[i-1][j+1]) dfs(i-1,j+1);

    if(i+1<g.size() && j-1>=0 && g[i+1][j-1] == '1' && !visited[i+1][j-1]) dfs(i+1,j-1);

    if(i+1<g.size() && j+1<g[i].length() && g[i+1][j+1] == '1' && !visited[i+1][j+1]) dfs(i+1,j+1);
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t; scanf("%d\n\n", &t);

    for(int cs=1; cs<=t; cs++)
    {
        while(getline(cin,line))
        {
            if(line == "") break;
            g.push_back(line);
        }

        /*for(int i=0; i<g.size(); i++)
        {
            cout << g[i] << endl;
        }
        cout << endl;*/


        memset(visited,false,sizeof visited);
        maxx = 0;
        for(int i=0; i<g.size(); i++)
        {
            for(int j=0; j<g[i].length(); j++)
            {

                if(g[i][j] == '1' && !visited[i][j])
                {
                    cnt = 0;
                    dfs(i,j);
                    if(cnt > maxx) maxx = cnt;
                }
            }
        }
        cout << maxx <<endl;
        if(cs < t) cout << endl;
        g.clear();

    }

    return 0;
}
