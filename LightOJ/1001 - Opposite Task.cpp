#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,n; cin >> t;

    for(int cs=1; cs<=t; cs++)
    {
        cin >> n;

        if(n < 10) cout << 0 << " " << n << endl;
        else
        {
            n-=10; cout << n << " " << 10 << endl;
        }
    }

    return 0;
}
