#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt","r",stdin);

    unsigned int a,b;
    int countCarry,carry;


    while(cin >> a >> b)
    {
        if(a==0 && b == 0) break;

        countCarry = 0;
        carry = 0;

        while(a>0 || b>0)
        {
            if((a%10) + (b%10) + carry >= 10)
            {
                carry = 1;
                countCarry++;
            }
            else carry = 0;

            a/=10;

            b/=10;
        }

        if(countCarry == 0) cout << "No carry operation.\n";
        else if(countCarry == 1) cout << countCarry << " carry operation.\n";
        else cout <<  countCarry << " carry operations.\n";

        countCarry = 0;
    }

    return 0;
}
