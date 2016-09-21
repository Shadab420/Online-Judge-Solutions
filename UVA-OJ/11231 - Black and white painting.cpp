#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("in.txt","r",stdin);
    long long int n,m,m1,c,cnt,w,b;

    while(scanf("%lld%lld%lld",&n,&m,&c))
    {
        if(n==0 && m==0 && c==0) break;
        cnt = 0;

        if(n == 8 && m==8 && c==0);
        else
        {
            n-=7,m-=7;

            if(c == 1)
            {
                w = (m/2) + (m%2); b = m-w;
            }
            else
            {
                b = (m/2) + (m%2); w = m-b;
            }
            cnt += w;
            c = 0;
            for(int i=n-1; i>=1; i--)
            {
                if(c == 1)
                {
                    cnt+=w; c = 0;
                }
                else
                {
                    cnt+=b; c = 1;
                }
            }

        }
        cout << cnt << endl;

    }

    return 0;
}
