#include <bits/stdc++.h>
using namespace std;

#define read2(num1, num2) scanf("%d %d", &num1, &num2)
#define read(num) scanf("%d", &num)
typedef long long int lli;

struct Person
{
    int id;
    int parent;
    int suspect;
    int rankk;

    Person(int _id)
    {
        id = _id;
        parent = id;
        rankk = 0;
        suspect = 0;
    }
};

vector<Person>v;

int findd(int x)
{
    if(v[x].parent == x) return x;
    else return v[x].parent = findd(v[x].parent);
}

void unionn(int x, int y)
{
    int parent1 = findd(x);
    int parent2 = findd(y);

    if(parent1 != parent2)
    {
        if(v[parent1].rankk >= v[parent2].rankk)
        {
            v[parent2].parent = parent1;
            v[parent1].rankk++;

        }
        else
        {
            v[parent1].parent = parent2;
            v[parent2].rankk++;
        }

        if(v[parent2].suspect == 1) v[parent1].suspect =1 ;
        else if(v[parent1].suspect == 1) v[parent2].suspect = 1;
    }
}

int main()
{
    freopen("input/in.txt","r",stdin);
    freopen("input/out.txt","w",stdout);

    int n, m, k;

    while(read2(n,m) != EOF)
    {
        if(n==0 && m==0) break;

        for(int i=0; i<n; i++)
        {
            Person p(i);
            v.push_back(p);
        }

        v[0].suspect = 1;

        int prevParent, a;

        for(int i=0; i<m; i++)
        {
            read(k);
            for(int j=0; j<k; j++)
            {
                read(a);

                if(j>0)
                {
                    unionn(prevParent,a);
                }
                prevParent = a;
            }
        }

        //Just for updating parents of all sets.
        for(int i=0; i<n; i++)
        {
            int p = findd(i);
        }

        int cntSuspect = 0;

        for(int i=0; i<v.size(); i++)
        {
            if(v[i].parent == v[i].id && v[i].suspect == 1)
            {
                for(int j=0; j<v.size(); j++)
                {
                    if(v[j].parent == v[i].id) cntSuspect++;
                }
            }
        }

        printf("%d\n", cntSuspect);

        v.clear();
    }

    return 0;
}

