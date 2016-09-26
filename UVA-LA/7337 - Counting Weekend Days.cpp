#include <bits/stdc++.h>
using namespace std;

/************************ START ************************/

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

/************************ END ************************/

int main()
{
    fin; fout;

    mapsi monthMap, dayMap;

    monthMap["JAN"] = 31;
    monthMap["FEB"] = 28;
    monthMap["MAR"] = 31;
    monthMap["APR"] = 30;
    monthMap["MAY"] = 31;
    monthMap["JUN"] = 30;
    monthMap["JUL"] = 31;
    monthMap["AUG"] = 31;
    monthMap["SEP"] = 30;
    monthMap["OCT"] = 31;
    monthMap["NOV"] = 30;
    monthMap["DEC"] = 31;

    dayMap["SUN"] = 1;
    dayMap["MON"] = 2;
    dayMap["TUE"] = 3;
    dayMap["WED"] = 4;
    dayMap["THU"] = 5;
    dayMap["FRI"] = 6;
    dayMap["SAT"] = 7;

    int t; ri(t);

    string month, day;

    for(int cs=1; cs<=t; cs++)
    {
        cin>>month>>day;

        int d = dayMap[day], cnt = 0;

        for(int i=1; i<=monthMap[month]; i++)
        {
            if(d==6 || d==7)
            {
                cnt++;
                if(d==7) d=0;
            }
            d++;
        }

        printf("%d\n", cnt);

    }

    return 0;
}
