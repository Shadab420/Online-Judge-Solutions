#include <bits/stdc++.h>
using namespace std;

#define pi 2*acos(0.0)

int main()
{
    //freopen("in.txt","r",stdin);
    int t; cin >> t;
    double radius,sa,ca;

    for(int cs=1; cs<=t; cs++)
    {
        cin >> radius;

        sa = 4*radius*radius;
        ca = pi*radius*radius;

        cout << "Case " << cs << ": " << fixed << setprecision(2) << sa - ca << endl;
    }

    return 0;
}
