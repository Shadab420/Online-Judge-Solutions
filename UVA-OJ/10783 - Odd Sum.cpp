#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt","r",stdin);

    int t,a,b; cin >> t;

    for(int cs=1; cs<=t; cs++)
    {
        cin >> a >> b;
        int sum = 0;
        while(a<=b)
        {
            if(a%2==1)
            {
                sum+=a;
                a+=2;
            }
            else a+=1;
        }
        cout << "Case " << cs << ": " << sum << endl;
    }

    return 0;
}
