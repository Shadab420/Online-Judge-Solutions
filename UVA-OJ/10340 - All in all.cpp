#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);

    string s,t;

    while(cin >> s >> t)
    {
        int pos = -1,ind, i;

        for(i=0; i<s.length(); i++)
        {
            ind = t.find(s.substr(i,1));

            if(ind == -1)
            {
                cout << "No\n"; break;
            }
            else
            {
                pos = ind;
                t.erase(0,ind+1);
            }

        }
        if(i == s.length()) cout << "Yes\n";
    }

    return 0;
}
