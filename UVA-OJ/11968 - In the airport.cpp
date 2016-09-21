#include <bits/stdc++.h>
using namespace std;

#define read(num) scanf("%d", &num)
#define readll(num) scanf("%lld", &num)
#define printcase(cs) printf("Case #%d: ", cs)

int main()
{
    freopen("input/in.txt","r",stdin);
    freopen("input/out.txt","w",stdout);
    int t,n,m,k; read(t);
    long long int sumAll, sub,diff,prices[1001],closestCake,closestDrink;

    for(int cs=1; cs<=t; cs++)
    {
        read(n); read(m); read(k);
        sumAll=0;
        for(int i=0; i<n; i++)
        {
            readll(prices[i]); sumAll+=prices[i];
        }
        sort(prices,prices+m);
        sort(prices+m+1, prices+m+k);

        diff = -1;
        for(int i=0; i<m; i++)
        {
            sub = abs(sumAll-(n*prices[i]));
            if(diff == -1 || diff > sub)
            {
                diff = sub;
                closestCake = prices[i];
            }
        }

        diff = -1;
        for(int i=m; i<m+k; i++)
        {
            sub = abs(sumAll-(n*prices[i]));
            if(diff == -1 || diff > sub)
            {
                diff = sub;
                closestDrink = prices[i];
            }
        }
        printcase(cs);
        printf("%lld %lld\n", closestCake, closestDrink);
    }

    return 0;
}
