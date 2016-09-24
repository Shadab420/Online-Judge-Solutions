#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t; cin >> t;
    long long int w;

    for(int cs=1; cs<=t; cs++)
    {
        cin >> w;
        bool found = false;
        cout << "Case " << cs << ": ";

        for(long long int i=w/2; i>=1; i/=2)
        {
            if(w%i==0)
            {
                if(i%2==1 && (w/i)%2 == 0)
                {
                    cout << i << " " << w/i << endl;
                    found = true;
                    break;
                }
                else if(i%2==0 && (w/i)%2 == 1)
                {
                    cout << w/i << " " << i << endl;
                    found = true;
                    break;
                }
            }

        }

        if(!found) cout << "Impossible\n";
    }

    return 0;
}
