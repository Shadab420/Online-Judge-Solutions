///Verdict: AC

#include <bits/stdc++.h>
using namespace std;

/******************** START OF CRAPS ********************/

#define fin             freopen("input/in.txt","r",stdin);
#define fout            freopen("input/out.txt","w",stdout);
#define ri(x)           scanf("%d", &x)
#define r2i(x,y)        scanf("%d %d", &x, &y)
#define rll(x)          scanf("%lld", &x)
#define r2ll(x,y)       scanf("%lld %lld", &x, &y)
#define imax            INT_MAX
#define imin            INT_MIN
#define pb              push_back
#define mp              make_pair
#define pi              acos(-1.0)
#define newl            "\n"
#define newlChar        '\n'
#define spChar          ' '
#define max3(a,b,c)     max(a,max(b,c))
#define min3(a,b,c)     min(a,min(b,c))
#define pCase(cs,ch)    printf("Case %d:%c", cs,ch)
#define iterAll(x)      x.begin(),x.end()
#define rIterAll(x)     x.rbegin(),x.rend()
#define fastreader      ios_base::sync_with_stdio(false); cin.tie(0)

typedef long long               ll;
typedef unsigned long long      ull;
typedef vector<int>             vi;
typedef vector<ll>              vll;
typedef vector<double>          vd;
typedef vector<string>          vs;
typedef vector<char>            vc;
typedef pair<int,int>           pii;
typedef map<int,int>            mapii;
typedef map<char,int>           mapci;
typedef map<string,int>         mapsi;

/******************** END OF CRAPS ********************/

int main()
{
    fin; fout;

    int t, amplitude, frequency; ri(t);

    for(int cs=1; cs<=t; cs++)
    {
        r2i(amplitude, frequency);

        for(int i=1; i<=frequency; i++)
        {
            for(int a=1; a<=amplitude; a++)
            {
                for(int b=1; b<=a; b++)
                {
                    printf("%d", a);
                }
                printf("\n");
            }

            for(int a=amplitude-1; a>=1; a--)
            {
                for(int b=1; b<=a; b++)
                {
                    printf("%d", a);
                }
                printf("\n");
            }
            if(cs < t || i<frequency) printf("\n");
        }
    }

    return 0;
}

