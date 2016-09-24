#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt","r",stdin);
    int t; cin >> t;
    int n;

    for(int cs=1; cs<=t; cs++)
    {
        cin >> n;

        string s = bitset< 64 >( n ).to_string();
        cout << s << endl;

        int cnt=0;

        for(int i=0; i<64; i++)
        {
            if(s[i] == '1') cnt++;
        }

        cout << "Case " << cs << ": ";
        if(cnt%2 == 0) cout << "even\n";
        else cout << "odd\n";

    }

    return 0;
}
