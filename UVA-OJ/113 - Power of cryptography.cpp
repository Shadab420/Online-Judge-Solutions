#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    long double n,num,ans;

    while(cin >> n >> num)
    {
        ans = exp(log(num)/n);

        cout << fixed << setprecision(0) << ans << endl;
    }

    return 0;
}

