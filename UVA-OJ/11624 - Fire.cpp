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
typedef map<int,int>            mapii;
typedef map<char,int>           mapci;
typedef map<string,int>         mapsi;

/******************** END OF CRAPS ********************/

#define Max 1010

struct Element
{
    int x;
    int y;
    int type;

    Element() {type=0;}
};

char grid[Max][Max];
int dist[Max][Max];
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
int row, col, minCell;
queue<Element>bfsq;

void bfs(int x, int y)
{
    if(x==0 || x==row-1 || y==0 || y==col-1)
    {
        minCell = 1;
        return;
    }

    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++) dist[i][j] = 1000000000;
    }

    dist[x][y] = 0;


    while(!bfsq.empty())
    {
        Element u = bfsq.front();
        bfsq.pop();

        Element v;

        if(u.type == 1)
        {
            for(int i=0; i<4; i++)
            {
                v.x = u.x+dx[i];
                v.y = u.y+dy[i];

                if(v.x>=0 && v.x<=row-1 && v.y>=0 && v.y<=col-1)
                {
                    if(grid[v.x][v.y]!='#' && grid[v.x][v.y] != 'F')
                    {
                        grid[v.x][v.y] = 'F';
                        v.type = 1;
                        bfsq.push(v);
                    }
                }
            }
        }

        else
        {
            for(int i=0; i<4; i++)
            {
                v.x = u.x+dx[i];
                v.y = u.y+dy[i];

                if(v.x>=0 && v.x<=row-1 && v.y>=0 && v.y<=col-1 && grid[v.x][v.y]=='.')
                {

                    if(dist[v.x][v.y] > dist[u.x][u.y]+1)
                    {
                        dist[v.x][v.y] = dist[u.x][u.y]+1;
                        if(v.x==0 || v.x==row-1 || v.y==0 || v.y==col-1)
                        {
                            minCell = min(minCell, dist[v.x][v.y]+1);
                        }
                    }
                    grid[v.x][v.y] = 'J';
                    bfsq.push(v);

                }
            }
        }

//        for(int i=0; i<row; i++)
//        {
//            for(int j=0; j<col; j++)
//            {
//                cout << grid[i][j];
//            }
//            cout << endl;
//        }
//        cout << endl;
    }
}


int main()
{
    //fin; fout;

    int t,jx,jy; ri(t);

    for(int cs=1; cs<=t; cs++)
    {
        r2i(row,col);

        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                cin>>grid[i][j];
                if(grid[i][j] == 'J')
                {
                    jx = i;
                    jy=j;
                }
                else if(grid[i][j] == 'F')
                {
                    Element e;
                    e.x = i;
                    e.y = j;
                    e.type = 1;
                    bfsq.push(e);
                }
            }
        }

        Element e;
        e.x = jx;
        e.y = jy;
        bfsq.push(e);



        minCell = INT_MAX;

        bfs(jx,jy);

        if(minCell == INT_MAX) printf("IMPOSSIBLE\n");
        else printf("%d\n", minCell);
    }

    return 0;
}
