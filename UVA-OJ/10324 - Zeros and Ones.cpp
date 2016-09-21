#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    string num;
    int cs = 0;

    while(cin >> num)
    {
        cs++;

        int q; cin >>  q;
        int first = q;
        if(q == first) cout << "Case " << cs << ":\n";
        first--;
        while(q>0)
        {

            int i,j;
            cin >> i >> j;
            int x = min(i,j);
            int y = max(i,j);

            bool alsame = true;

            if(x != y)
            {
                for(; x<y; x++)
                {
                    if(num[x] != num[x+1])
                    {
                        alsame = false;
                        break;
                    }
                }
            }

            if(alsame == true) cout << "Yes\n";
            else cout << "No\n";
            q--;
        }
    }


    return 0;
}
