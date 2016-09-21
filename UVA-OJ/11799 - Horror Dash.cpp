#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    int t,n,x,mx; cin >> t;

    for(int i=1; i<=t; i++)
    {
        cin >> n;
        mx = 0;

        for(int j=0; j<n; j++)
        {
            cin >> x;
            mx = max(x,mx);
        }
        cout << "Case " << i << ": " << mx << endl;
    }

    return 0;
}
