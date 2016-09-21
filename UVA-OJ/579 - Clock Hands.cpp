#include <bits/stdc++.h>
using namespace std;

int main()
{
    double h,m,angle,angleH,angleM;
    char c;

    while(cin >> h >> c >> m)
    {
        if(h == 0 && m == 0) break;


        angleH = h*30.0 + (m*0.5);
        angleM = m * 6.0;
        angle = fabs(angleH - angleM);
        if(angle>180.0) printf("%0.3f\n", fabs(360.000 - angle));

        else printf("%0.3f\n", angle);

    }

    return 0;
}
