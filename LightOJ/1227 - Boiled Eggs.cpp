#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t,n,p,q,w,sum,c;

    cin >> t;

    for(int i=1; i<=t; i++)
    {
        cin >> n >> p >> q;
        sum = c = 0;

        for(int j=1; j<=n; j++)
        {
            cin >> w;

            if(sum+w > q) continue;
            else
            {
                if(c + 1 > p) continue;
                else
                {
                    sum += w;
                    c++;
                }
            }
        }
        cout << "Case " << i << ": " << c << endl;
    }

    return 0;
}
