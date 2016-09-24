#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int aBin[32] = {0}, bBin[32] = {0}, i;

bool aBinFull = false, bBinFull = false;

void bin(long long int x)
{
    i=31;

    if(aBinFull == false)
    {
        while(x > 0)
        {
            aBin[i] = x%2;
            x/=2;
            i--;
        }
        aBinFull = true;
    }
    else
    {
        while(x > 0)
        {
            bBin[i] = x%2;
            x/=2;
            i--;
        }
        bBinFull = true;
    }
}

long long int calc()
{
    long long int r = 0;

    int p=0;

    for(int j=31; j>=0; j--)
    {
        if(aBin[j] == bBin[j])
        {
            p++;
        }
        else if(aBin != bBin)
        {
            r = r + pow(2,p);
            p++;
        }
    }

    return r;

}

int main()
{
    long long int a,b;

    while(cin >> a >> b)
    {
        bin(a);
        bin(b);
        cout << calc() << endl;


        aBinFull = bBinFull = false;
        memset(aBin,0,sizeof(aBin));
        memset(bBin,0,sizeof(bBin));
    }


    return 0;
}
