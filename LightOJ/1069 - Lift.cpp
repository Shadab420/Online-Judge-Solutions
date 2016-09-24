#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,myPos,lPos;

    cin >> t;
    for(int i=1; i<=t; i++)
    {
        cin >> myPos >> lPos;

        if(lPos >= myPos) cout << "Case " << i << ": " << lPos*4+19 << endl;
        else
        {
            int firstPos = myPos-lPos;
            cout << "Case " << i << ": " << (firstPos)*4+19+myPos*4 << endl;
        }
    }

    return 0;
}
