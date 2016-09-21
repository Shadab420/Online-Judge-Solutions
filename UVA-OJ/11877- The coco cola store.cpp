#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);

    int n;

    while(cin >> n)
    {
        if(n==0) break;

        int enjoy = 0;
        int get=0;
        while(n>=3)
        {
            enjoy+=(n/3);
            get+=(n%3);
            n/=3;
            n+=get;
            get=0;
        }
        if(n==2) enjoy++;
        cout << enjoy << endl;
    }

    return 0;
}

