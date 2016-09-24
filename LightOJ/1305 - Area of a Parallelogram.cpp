#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t,ax,ay,bx,by,cx,cy,dx,dy; cin >> t;

    for(int cs=1; cs<=t; cs++)
    {
        cin >> ax >> ay >> bx >> by >> cx >> cy;

        dx = cx + (ax-bx);
        dy = ay + (cy-by);

        int q=((ax*by)+(bx*cy)+(cx*dy)+(dx*ay))-((ay*bx)+(by*cx)+(cy*dx)+(dy*ax));
        if(q<0) q*=-1;

        int area=0.5*q;

        cout << "Case " << cs << ": " << dx << " " << dy << " " << area << endl;
    }

    return 0;
}
