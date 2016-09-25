#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string fp, sp, type;
    int n,x,fpc=0,spc=0;


    while(cin >> fp >> sp >> type)
    {
        if(fp == "#" && sp == "#" && type == "#") break;

        cin >> n;
        for(int i=0; i<n; i++)
        {
            cin >> x;
            if(type == "even")
            {
                if(x%2==0) spc++;
                else fpc++;
            }
            else
            {
                if(x%2==1) spc++;
                else fpc++;
            }

        }

        cout << fp << " " << fpc << " " << sp << " " << spc << endl;

        fpc = spc = 0;

    }

    return 0;
}
