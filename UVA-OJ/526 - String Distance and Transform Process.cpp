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

char str1[101], str2[101];
int len1,len2;
int dp[101][101];

///Get operations performed.
void printActualEdits();

///get min edit distance between two words.
int MinEditDistance()
{
    dp[0][0] = 0;
    for(int i=1; i<=len1; i++) dp[i][0] = i;
    for(int j=1; j<=len2; j++) dp[0][j] = j;

    for(int i=1; i<=len1; i++)
    {
        for(int j=1; j<=len2; j++)
        {
            ///If current characters are equal then we
            ///just need to copy this char with 0 cost.
            if(str1[i-1] == str2[j-1])
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else
            {
                ///The current characters are not same so we
                ///need to check which operation gives minimum cost
                ///we know the optimal min cost of the previous strings
                ///without current chars. we take the minimum and add 1
                ///or preferred cost for current operation.
                dp[i][j] = 1 + min3(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]);
            }
        }
    }
    ///The min distance between 2 strings will finally
    ///stored in the lower right cell.
    return dp[len1][len2];
}

void printActualEdits()
{
    ///we start from back.
    ///i for the str1 that need 2 be converted.
    ///j is for target string.
    int i = len1;
    int j = len2;
    int serial=0;

    ///if we will continue until we reach dp[0][0] cell
    while(i || j)
    {
        ///If current chars are eq then its a copy so just go diagonally.
        if(str1[i-1] == str2[j-1])
        {
            i--;
            j--;
            continue;
        }

        printf("%d ", ++serial);

        ///Check if current i-1th char is deleted.
        if(i>0 && dp[i][j] == dp[i-1][j]+1)
        {
            printf("Delete %d\n",i);
            //str1.erase(i-1,1);
            i--;
        }
        ///Otherwise check if current j-1th char is inserted.
        else if(j>0 && dp[i][j] == dp[i][j-1]+1)
        {
            printf("Insert %d,%c\n",i+1, str2[j-1]);
            //str1.insert(i,1,str2[j-1]);
            j--;
        }

        ///Else it must be a substitution/replacement.
        else if(i>0 && j>0)
        {
            printf("Replace %d,%c\n",i, str2[j-1]);
            //str1[i-1] = str2[j-1];
            i--; j--;
        }
    }
    //cout << str1 << endl;
}

int main()
{
    //fin; fout;

    int cs=0;

    while(gets(str1))
    {
        cs++;
        gets(str2);
        len1 = strlen(str1);
        len2 = strlen(str2);
        if(cs>1) puts("");
        int minEditDis = MinEditDistance();
        printf("%d\n", minEditDis);
        if(minEditDis > 0) printActualEdits();
    }

    return 0;
}


