#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    unsigned int n,cnt,a;

    while(cin>>n && n!=0)
    {
        a = cnt = 0;
        for(int i=0; i<32; i++)
        {
            if(n&(1<<i))
            {
                int currPart = 1<<i;
                cnt++;
                if(cnt%2==1) a += currPart;
            }
        }

        cout << a << " " << n-a << endl;
    }

    return 0;
}
