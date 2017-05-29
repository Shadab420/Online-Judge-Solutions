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

int n, arr[101][101];
int t[101];

int Kadane()
{
    int finalMaxSum = t[0], currMaxSum = t[0];

    for(int i=1; i<n; i++)
    {
        currMaxSum = max(t[i],currMaxSum+t[i]);
        finalMaxSum = max(finalMaxSum,currMaxSum);
    }
    return finalMaxSum;
}

int getMax_2D_Rect_Sum()
{
    int currMax, finalMax=imin;

    for(int left=0; left<n; left++)
    {
        for(int i=0; i<n; i++) t[i]=0;

        for(int right=left; right<n; right++)
        {
            for(int i=0; i<n; i++)
            {
                t[i]+=arr[i][right];
            }
            currMax = Kadane();
            finalMax = max(finalMax,currMax);
        }
    }

    return finalMax;
}

int main()
{
    fin; fout;

    while(ri(n)!=EOF)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++) ri(arr[i][j]);
        }

        printf("%d\n", getMax_2D_Rect_Sum());
    }

    return 0;
}

