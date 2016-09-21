#include <bits/stdc++.h>
using namespace std;

int n,l,a,b;
bool invalid;

vector<int>g[200];

bool visited[200];
char color[200];
queue<int>bfsq;

void bfs(int start)
{
    //cout << start << endl;

    if(!visited[start])
    {
        bfsq.push(start);
        visited[start] = true;
        color[start] = 'w';
    }

    for(int i=0; i<g[start].size(); i++)
    {
        int node = g[start][i];
        if(!visited[node])
        {
            bfsq.push(node);
            visited[node] = true;
            if(color[start] == 'w')
            {
                color[node] = 'b';
            }
            else color[node] = 'w';
        }
        else
        {
            if(color[start] == color[node])
            {
                invalid = true;
                break;
            }
        }

    }
    if(invalid) return;
    bfsq.pop();
    if(!bfsq.empty())
    {

        bfs(bfsq.front());
    }

}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    while(cin >> n && n!=0)
    {
        cin >> l;

        if(l==0)
        {
            cout <<"BICOLORABLE.\n"; continue;
        }

        for(int i=0; i<n; i++)
        {
            g[i].clear();
        }

        memset(visited,false,sizeof visited);
        memset(color,'z',sizeof color);

        queue<int>emptyq;
        swap(bfsq,emptyq);

        for(int i=0; i<l; i++)
        {
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }

        invalid = false;
        bfs(0);
        if(!invalid) cout << "BICOLORABLE.\n";
        else cout << "NOT BICOLORABLE.\n";
    }

    return 0;
}
