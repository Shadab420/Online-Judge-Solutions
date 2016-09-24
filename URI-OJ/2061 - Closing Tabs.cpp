#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int n,m; scanf("%d%d", &n, &m);
    string cmd;

    for(int i=0; i<m; i++)
    {
        cin >> cmd;
        if(cmd == "fechou") n+=2;
        n--;
    }
    cout << n << endl;

    return 0;
}
