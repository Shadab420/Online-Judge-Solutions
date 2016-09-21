#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin>>t;
    double c,f;

    for(int cs=1; cs<=t; cs++)
    {
        cin>>c>>f;

        double ctof = 1.8000 * c + 32;
        f+=ctof;
        cout << "Case " << cs << ": " << fixed << setprecision(2) << 0.55555555 *(f-32) << endl;
    }

    return 0;
}
