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
#define forloop(i,n)     for(; i<=n; i++)

typedef long long               ll;
typedef unsigned long long      ull;
typedef vector<int>             vi;
typedef vector<ll>              vll;
typedef vector<double>          vd;
typedef vector<string>          vs;
typedef vector<char>            vc;
typedef pair<int,int>           pii;
typedef pair<char,int>          pci;
typedef map<int,int>            mapii;
typedef map<char,int>           mapci;
typedef map<string,int>         mapsi;

/******************** END OF CRAPS ********************/

int main()
{
    //fin; fout;

    int t,cs; ri(t); cs=1;

    int row, col, impPixByte, nonImpPixByte;

    forloop(cs,t)
    {
        r2i(row,col);
        r2i(impPixByte, nonImpPixByte);

        char c;

        map<char,int>charmap;

        char maxC;
        int maxOcc = INT_MIN;

        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                cin>>c;
                charmap[c]++;

                if(charmap[c] > maxOcc) maxOcc = charmap[c];
            }
        }

        int cntMax=0, cntOthers=0;

        for(int i=0; i<26; i++)
        {
            if(charmap[i+'A'] == maxOcc) cntMax+=charmap[i+'A'];
            else cntOthers+=charmap[i+'A'];
        }

        pCase(cs,spChar);
        cout << cntMax*impPixByte + cntOthers*nonImpPixByte << endl;
    }

    return 0;
}

