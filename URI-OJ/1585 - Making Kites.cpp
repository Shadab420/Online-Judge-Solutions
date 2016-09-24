#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("i.txt","r",stdin);
    int t,x,y; cin >> t;

    for(int cs=1; cs<=t; cs++)
    {
        cin >> x >> y;
        cout << (x *y)/2 << " cm2\n";
    }

    return 0;
}
