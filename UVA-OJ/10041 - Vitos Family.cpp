#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    int t,r,x; cin >> t;
    vector<int>v;

    for(int cs=1; cs<=t; cs++)
    {
        cin >> r;
        for(int i=1; i<=r; i++)
        {
            cin >> x; v.push_back(x);
        }
        sort(v.begin(),v.end());

        int mid = v[r/2],sum=0;

        for(int i=0; i<r; i++)
        {
            sum += abs(v[i]-mid);
        }
        cout << sum << endl;

        v.clear();
    }

    return 0;
}

