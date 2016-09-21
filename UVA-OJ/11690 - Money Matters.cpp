#include <bits/stdc++.h>

using namespace std;

int t,n,m,o;
bool possible;

class Friend
{
public:
    int fid;
    int rankk;
    int parent;
    int money;

    Friend(int id, int r, int parnt, int mony)
    {
        fid = id; rankk = r; parent = parnt, money = mony;
    }


};

vector<Friend>frnd;

int findd(int p)
{
    if(frnd[p].parent == p) return p;
    else return frnd[p].parent = findd(frnd[p].parent);
}

void unionn(int a, int b)
{
    int parent1 = findd(a);
    int parent2 = findd(b);

    if(parent1 == parent2) return;

    if(frnd[parent1].rankk < frnd[parent2].rankk)
    {
        frnd[parent1].parent = parent2;
        frnd[parent2].rankk++;
        frnd[parent2].money += frnd[parent1].money;
        frnd[parent1].money = 0;
    }
    else
    {
        frnd[parent2].parent = parent1;
        frnd[parent1].rankk++;
        frnd[parent1].money += frnd[parent2].money;
        frnd[parent2].money = 0;
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    scanf("%d", &t);

    for(int cs=1; cs<=t; cs++)
    {
        scanf("%d%d", &n, &m);

        if(m == 0)
        {
            printf("IMPOSSIBLE\n"); continue;
        }
        frnd.clear();
        for(int i=0; i<n; i++)
        {
            scanf("%d", &o);

            Friend f(i,0,i,o);
            frnd.push_back(f);
        }
        int a, b;
        for(int i=0; i<m; i++)
        {
            scanf("%d%d", &a, &b);

            unionn(a,b);
        }
        possible = true;

        for(int i=0; i<n; i++)
        {
            if(frnd[i].parent == i)
            {
                if(frnd[i].money == 0);
                else
                {
                    possible = false;
                    break;
                }

            }

        }

        if(possible) printf("POSSIBLE\n");
        else printf("IMPOSSIBLE\n");
    }

    return 0;
}
