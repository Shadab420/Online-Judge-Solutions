#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);

    double a,b,c;

    while(cin >> a >> b >> c)
    {
        if(a<=0||b<=0||c<=0)
        {
            cout << "The radius of the round table is: 0.000\n";
        }
        else
        {
            double s = (a+b+c)/2;

            double result = sqrt(s*(s-a) * (s-b) * (s-c))/s;

            cout << fixed << setprecision(3) << "The radius of the round table is: " << result << endl;
        }
    }

    return 0;
}
