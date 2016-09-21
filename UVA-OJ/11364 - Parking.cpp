#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    int t,n,x[20],sum; cin >> t;

    for(int cs=1; cs<=t; cs++)
    {
        cin >> n;
        for(int i=0; i<n; i++) cin >> x[i];
        sort(x,x+n);
        sum  = 0;
        for(int i=0; i<n-1; i++) sum+=(x[i+1] - x[i]);

        cout << sum*2 << endl;
    }

    return 0;
}
