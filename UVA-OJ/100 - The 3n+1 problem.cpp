#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    long long int i,j,icpy,icpy2,len,maxlen;
    bool swapped;


    while(cin>> i >> j)
    {
        swapped = false;
        if(i>j)
        {
            swap(i,j);
            swapped = true;
        }
        icpy = i; icpy2 = i;maxlen = 0;
        while(i<=j)
        {
            len=0;
            while(1)
            {
                if(i==1)
                {
                    len++;
                    break;
                }
                if(i%2==1) i = 3*i+1;
                else i=i/2;

                len++;

            }

            if(len > maxlen)
            {
                maxlen = len;
            }
            icpy2++;
            i = icpy2;

        }
        if(swapped)
        {
            swap(icpy,j);
        }

        cout << icpy << " " << j << " " << maxlen << endl;

    }

    return 0;
}
