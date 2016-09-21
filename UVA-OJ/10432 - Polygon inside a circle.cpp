#include <bits/stdc++.h>
using namespace std;
double pi = 2*acos(0);
int main()
{
    int n;
    double r;
    while(cin >> r >> n)
    {
        cout << fixed << setprecision(3) << 0.5*n*r*r*sin(2*pi/n) << endl;
    }
    return 0;
}

