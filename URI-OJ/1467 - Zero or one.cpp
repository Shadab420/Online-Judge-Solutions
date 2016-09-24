#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("i.txt","r",stdin);
    int a,b,c;

    while(cin >> a >> b >> c)
    {
        if(a == b && b == c) cout << "*\n";
        else if(a == b && c!=a) cout << "C\n";
        else if(b == c && a!=b) cout << "A\n";
        else cout << "B\n";
    }

    return 0;
}
