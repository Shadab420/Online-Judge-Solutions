#include <bits/stdc++.h>
using namespace std;

#define read(num) scanf("%d", &num)

int t, noOfEmps,n,frnd,start, firstDayBoom, maxDailyBoom;
vector<int>g[2501];
int dist[2501];
map<int,int>cnt;

void bfs(int s)
{
    queue<int>q;
    for(int i=0; i<noOfEmps; i++) dist[i] = 1000000000;
    q.push(s);
    dist[s] = 0;
    int day;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        day = dist[u]+1;
        for(int i=0; i<g[u].size(); i++)
        {
            int v = g[u][i];

            if(dist[v] > dist[u]+1)
            {
                int prev = dist[v];
                dist[v] = dist[u]+1;

                if(prev == 1000000000) cnt[day]++;

                q.push(v);
            }
        }
        if(cnt[day] > maxDailyBoom)
        {
            maxDailyBoom = cnt[day];
            firstDayBoom = day;
        }
    }
}

int main()
{
    freopen("input/in.txt","r",stdin);
    freopen("input/out.txt","w",stdout);
    read(noOfEmps);
    for(int i=0; i<noOfEmps; i++)
    {
        read(n);
        for(int j=0; j<n; j++)
        {
            read(frnd);
            g[i].push_back(frnd);
        }
    }

    read(t);

    for(int cs=1; cs<=t; cs++)
    {
        read(start);
        firstDayBoom = 0;
        maxDailyBoom = -INT_MAX;
        cnt.clear();
        bfs(start);
        if(maxDailyBoom==0) cout << 0 << endl;
        else cout << maxDailyBoom << " " << firstDayBoom << endl;
    }

    return 0;
}
