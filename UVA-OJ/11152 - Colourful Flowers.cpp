#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0.0)

int main()
{
    double a,b,c;

    while(cin >> a >> b >> c)
    {
        double s = (a+b+c)/2;
        double violetArea = sqrt(s*(s-a)*(s-b)*(s-c));
        double roseRadius = violetArea/s;
        double roseArea = PI*roseRadius*roseRadius;
        //double sunflowersRadius = (a*b*c)/sqrt((a+b+c)*(b+c-a)*(c+a-b)*(a+b-c));
        double sunflowersRadius = (a*b*c)/(4*violetArea);
        double sunflowersArea = PI*sunflowersRadius*sunflowersRadius - violetArea;
        violetArea -= roseArea;

        printf("%0.4f %0.4f %0.4f\n", sunflowersArea, violetArea, roseArea);
    }
}


