#include <bits/stdc++.h>
using namespace std;

#define read(filename) freopen(filename,"r",stdin)

int main()
{
    read("i.txt");
    int x[5], y[5];
    bool compatible = true;

    for(int i=0; i<5; i++) cin >> x[i];
    for(int i=0; i<5; i++)
    {
        cin >> y[i];
        if(y[i] == x[i]) compatible = false;
    }
    if(compatible) cout << "Y\n";
    else cout << "N\n";

    return 0;
}
