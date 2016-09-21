#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    long r, i;
    while(b!=0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t; cin >> t;
    string s1,s2;

    for(int cs=1; cs<=t; cs++)
    {
        cin >> s1 >> s2;
        int n1 = (int) bitset<32>(s1).to_ulong();
        int n2 = (int) bitset<32>(s2).to_ulong();
        bool bothDivisible = false;

        if(n1 == n2)
        {
            bothDivisible = true;;
        }
        else if(n1%2==0 && n2%2==0)  bothDivisible = true;
        else
        {
            int getDivisor = gcd(n1,n2);
            if(getDivisor > 1) bothDivisible = true;
        }

        if(bothDivisible) cout << "Pair #" << cs << ": All you need is love!\n";
        else cout << "Pair #" << cs << ": Love is not all you need!\n";
    }

    return 0;
}
