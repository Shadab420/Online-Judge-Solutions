#include <bits/stdc++.h>
using namespace std;


class peoples
{
public:
    int pid;
    int rankk;
    int parent;
};

 peoples p[30000];
 int friends[30000];



int findd(int people)
{
    if(p[people].parent == people) return people;
    else return p[people].parent = findd(p[people].parent);
}

void unionn(int people1, int people2)
{
    int parent1 = findd(people1);
    int parent2 = findd(people2);

    if(parent1 == parent2) return;
    if(p[parent1].rankk < p[parent2].rankk)
    {

        p[parent1].parent = parent2;
        p[parent2].rankk++;
        friends[parent2-1] += friends[parent1-1];
        friends[parent1-1] = 0;

    }
    else
    {
        p[parent2].parent = parent1;
        p[parent1].rankk++;
        friends[parent1-1] += friends[parent2-1];
        friends[parent2-1] = 0;
    }

}


int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int t,n,m,a,b; scanf("%d", &t);

    for(int cs=1; cs<=t; cs++)
    {
        scanf("%d %d", &n, &m);

        if(m == 0)
        {
            cout << 0 << endl;
            continue;
        }

        memset(friends,0,sizeof(friends));

        for(int i=1; i<=n; i++)
        {
            p[i].pid = p[i].parent = i; p[i].rankk = 0;
            friends[i-1] = 1;
        }

        for(int i=1; i<=m; i++)
        {
            scanf("%d %d", &a, &b);
            if(a!=b && p[a].parent != p[b].parent)
            {
                unionn(a,b);

            }
        }
        sort(friends, friends+n);
        cout << friends[n-1] << endl;
    }

    return 0;
}
