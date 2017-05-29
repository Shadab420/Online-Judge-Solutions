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

string fib[5001];

string add(string a, string b)
{
    string ans="";

    int i,carry=0, diff = a.length()-b.length();

    for(i=b.length()-1; i>=0; i--)
    {
        int res = (a[i+diff]-'0')+(b[i]-'0')+carry;
        ans+= (res%10)+'0';
        carry = res/10;
    }
    //cout << carry << endl;
    i+=diff;
    //cout << i << endl;

    while(carry)
    {
        int res;

        while(i>=0)
        {
            res = (a[i]-'0')+(carry%10);
            //cout << res << endl;
            ans+=(res%10)+'0';
            carry = res/10;
            i--;
        }

        if(carry) ans += (carry%10)+'0';

        carry/=10;
    }

    while(i>=0)
    {
        ans+=a[i];
        i--;
    }

    reverse(ans.begin(), ans.end());

    return ans;

}

void fibonacci(int n)
{
    fib[0] = "0";
    fib[1] = "1";

    for(int i=2; i<=n; i++)
    {
        fib[i] = add(fib[i-1],fib[i-2]);
    }
}

int main()
{
    fin; fout;

    fibonacci(5000);

    int n;

    while(ri(n)!=EOF)
    {
        cout << "The Fibonacci number for "<< n << " is " << fib[n] << "\n";
    }

    return 0;
}
