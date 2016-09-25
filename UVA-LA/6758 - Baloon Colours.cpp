#include <bits/stdc++.h>
using namespace std;

#define read(num) scanf("%d", &num)

int main()
{
    int t,n,x,y,curr; read(t);
    bool easyRightColour, hardRightColour;

    for(int cs=1; cs<=t; cs++)
    {
        read(n); read(x); read(y);
        easyRightColour = hardRightColour = true;

        for(int i=1; i<=n; i++)
        {
            read(curr);
            if(i==1)
            {
                if(curr == x) easyRightColour = false;
            }
            else if(i==n)
            {
                if(curr==y) hardRightColour = false;
            }
        }

        if(easyRightColour && hardRightColour) cout << "OKAY\n";
        else if(!easyRightColour && !hardRightColour) cout << "BOTH\n";
        else if(!easyRightColour && hardRightColour) cout << "EASY\n";
        else if(easyRightColour && !hardRightColour) cout << "HARD\n";
    }

    return 0;
}
