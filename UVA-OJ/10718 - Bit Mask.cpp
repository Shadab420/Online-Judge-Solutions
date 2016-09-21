#include <bits/stdc++.h>
using namespace std;

#define readll(num1, num2, num3) scanf("%lld %lld %lld", &num1, &num2, &num3)
typedef long long int lli;

bool check(lli n, int pos)
{
    if((n & (1LL<<pos))) return true;
    else return false;
}

lli sett(lli mask, int pos)
{
    return (mask | (1LL<<pos));
}

int main()
{
    lli n,l,u,mask,currVal,currMask;

    while(readll(n,l,u) != EOF)
    {
        currMask = 0;

        for(int i=31; i>=0; i--)
        {
            lli a = sett(currMask,i);
            if(a<=u)
            {
                if(a<=l)
                {
                    currMask = a;
                }
                else
                {
                    if(!check(n,i))
                    {
                        currMask = a;
                    }

                }
            }
        }
        cout << currMask << endl;
    }

    return 0;
}
