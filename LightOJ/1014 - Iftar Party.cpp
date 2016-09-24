#include <bits/stdc++.h>
using namespace std;

#define read(num) scanf("%d", &num)

int main()
{
    freopen("input/in.txt","r",stdin);
    freopen("input/out.txt","w",stdout);
    int t,p,l; read(t);

    for(int cs=1; cs<=t; cs++)
    {
        read(p); read(l);

        printf("Case %d: ", cs);
        p-=l;

        if(p<=l)
        {
            printf("impossible\n"); continue;
        }
        else if(p==0 && l == 0)
        {
            printf("1\n"); continue;
        }

        int range = sqrt(p);
        vector<int>v;
        for(int i = 1; i<=range; i++)
        {
            if(p%i==0)
            {
                if(i>l) v.push_back(i);
                if(p/i > l && i!=p/i) v.push_back(p/i);
            }
        }

        if(v.size() == 0) printf("%d", p);
        else
        {
            sort(v.begin(), v.end());
            printf("%d", v[0]);
            for(int i=1; i<v.size(); i++) printf(" %d", v[i]);
        }
        printf("\n");
    }

    return 0;
}
