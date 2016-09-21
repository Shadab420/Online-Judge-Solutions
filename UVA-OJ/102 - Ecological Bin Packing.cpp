#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);

    int b1,b2,b3,g1,g2,g3,c1,c2,c3;

    while(cin>>b1>>g1>>c1>>b2>>g2>>c2>>b3>>g3>>c3)
    {
        int minn = INT_MAX,temp;
        string order;

        temp = c1+g1+b2+g2+b3+c3;
        if(temp < minn)
        {
            minn = temp;
            order = "BCG";
        }

        temp = c1+g1+b2+c2+b3+g3;
        if(temp < minn)
        {
            minn = temp;
            order = "BGC";
        }
        temp = b1+g1+c2+g2+b3+c3;
        if(temp < minn)
        {
            minn = temp;
            order = "CBG";
        }
        temp = b1+g1+b2+c2+g3+c3;
        if(temp < minn)
        {
            minn = temp;
            order = "CGB";
        }
        temp = c1+b1+c2+g2+b3+g3;
        if(temp < minn)
        {
            minn = temp;
            order = "GBC";
        }
        temp = c1+b1+b2+g2+g3+c3;
        if(temp < minn)
        {
            minn = temp;
            order = "GCB";
        }

        cout << order << " " << minn << endl;
    }

    return 0;
}
