#include <bits/stdc++.h>

using namespace std;

bool compare(int x, int y)
{
    if(x>y) return true;
    return false;
}

int main()
{
    freopen("in.txt","r",stdin);
    int t,x; cin >> t;
    vector<int>v1,v2;
    cout << "Lumberjacks:\n";
    for(int cs=1; cs<=t; cs++)
    {
        for(int i=1; i<=10; i++)
        {
            cin>>x; v1.push_back(x);
        }
        v2 = v1;
        sort(v2.begin(), v2.end());

        if(v1 == v2) cout << "Ordered\n";
        else
        {
            sort(v2.begin(), v2.end(),compare);
            if(v1 == v2) cout << "Ordered\n";
            else cout << "Unordered\n";
        }
        v1.clear(); v2.clear();
    }

    return 0;
}
