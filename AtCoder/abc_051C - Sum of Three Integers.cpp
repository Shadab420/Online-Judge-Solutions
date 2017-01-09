///Verdict:AC
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x,y,z,k,s;

    while(scanf("%d %d", &k, &s)!=EOF)
    {
        int cnt = 0;

        for(x=0; x<=k; x++)
        {
            for(y=0; y<=k; y++)
            {
                z = s-(x+y);

                if(z>=0 && z<=k)
                {
                    cnt++;
                }
            }
        }
        printf("%d\n", cnt);
    }

    return 0;
}
