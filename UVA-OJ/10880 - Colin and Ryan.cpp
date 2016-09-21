#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define read(num) scanf("%lld",&num)

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t; read(t);

    ll c,r;

    for(int cs=1; cs<=t; cs++)
    {
        read(c); read(r);


        if(c == r)
        {
            printf("Case #%d: 0\n", cs);
            continue;
        }

        ll check = c-r;

        vector<ll>ans;
        for(ll i=1; i<=sqrt(check); i++)
        {
            //cout << c%i << endl;
            if(check%i == 0)
            {
                ans.push_back(i);
                if(check/i != i) ans.push_back(check/i);
            }
        }

        sort(ans.begin(),ans.end());

        printf("Case #%d:", cs);

        for(int i=0; i<ans.size(); i++)
        {
            if(ans[i] > r)
            {
                printf(" %lld", ans[i]);
            }
        }
        printf("\n");
    }

    return 0;
}
