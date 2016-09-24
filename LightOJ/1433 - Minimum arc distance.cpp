#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t,ox,oy,ax,ay,bx,by; cin >> t;

    for(int cs=1; cs<=t; cs++)
    {
        cin >> ox >> oy >> ax >> ay >> bx >> by;

        double ab = sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by));
        double oa = sqrt((ox-ax)*(ox-ax)+(oy-ay)*(oy-ay));
        double ob = sqrt((ox-bx)*(ox-bx)+(oy-by)*(oy-by));


        double angle = acos(1 - 0.5*pow((ab/ob),2)); ;



        printf("Case %d: %.8f\n", cs, ob*angle);
    }

    return 0;
}
