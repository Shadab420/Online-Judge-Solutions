#include <bits/stdc++.h>
using namespace std;

int n,m,p1,p2,cs=0,sets;
int peoples[50005];
int rankk[50005];

int findd(int p)
{
    if(peoples[p] == p) return p;
    else return peoples[p] = findd(peoples[p]);
}

void unionn(int a, int b)
{
    int parent1 = findd(a);
    int parent2 = findd(b);

    if(rankk[parent1] < rankk[parent2])
    {
        peoples[parent1] = parent2;
        rankk[parent2]++;

    }
    else
    {
        peoples[parent2] = parent1;
        rankk[parent1]++;
    }

}


int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    while(scanf("%d%d", &n,&m) != EOF)
    {
        if(n == 0 && m == 0) break;

        cs++;
        if(n==0 || m == 0)
        {
            cout << "Case " << cs << ": " << 0 << endl; continue;
        }

        for(int i=1; i<=n; i++)
        {
            peoples[i] = i;
            rankk[i] = 0;
        }

        for(int i=1; i<=m; i++)
        {
            scanf("%d %d", &p1,&p2);
            unionn(p1,p2);
        }

        int cnt = 0;
        for(int i=1; i<=n; i++)
        {
            if(peoples[i] ==  i) cnt++;
        }

        cout << "Case " << cs << ": " << cnt << endl;

    }

    return 0;
}
