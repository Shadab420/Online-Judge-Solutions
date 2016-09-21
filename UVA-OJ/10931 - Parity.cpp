#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int i,icpy;

    while(cin >> i && i > 0)
    {
        icpy = i;
        string bin = bitset<32>(i).to_string();
        int cntOne=0;
        bool eraseZeros = false;
        for(int i=0; i<bin.length(); i++)
        {
            if(bin[i] == '1') cntOne++;
            if(cntOne == 1 && !eraseZeros)
            {
                bin.erase(0,i);
                eraseZeros = true;
                i=0;
            }
        }

        cout << "The parity of " << bin << " is " << cntOne << " (mod 2).\n";
    }

    return 0;
}
