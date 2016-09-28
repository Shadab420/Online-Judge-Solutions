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

struct Question
{
    int d;
    int s;
    char r;

    bool operator < (Question q) const
    {
        if(d == q.d) return s < q.s;
        return d < q.d;
    }
};


int main()
{
    fin; fout;

    int t; ri(t);

    int n;


    for(int cs=1; cs<=t; cs++)
    {
        ri(n);

        Question q;
        vector<Question>ques;

        int maxx = INT_MIN;

        int notleakedIncorrect[11] = {0};

        for(int i=0; i<n; i++)
        {
            r2i(q.d,q.s);
            cin>>q.r;

            if(q.s==0 && q.r=='i') notleakedIncorrect[q.d]++;

            else if(q.s==1 && q.r=='c') ques.push_back(q);
        }

        //sort(ques.begin(),ques.end());

        for(int i=1; i<=10; i++) notleakedIncorrect[i]+=notleakedIncorrect[i-1];

        int suspecious = 0;

//        for(int i=1; i<=10; i++) cout << notleakedIncorrect[i] << " ";
//        cout << endl;

        for(int i=0; i<ques.size(); i++)
        {

                //for(int j=1; j<ques[i].d; j++)
                {
                    suspecious+=notleakedIncorrect[ques[i].d-1];
                }

        }
        printf("%d\n",suspecious);

    }

    return 0;
}
