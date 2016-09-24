#include <bits/stdc++.h>
using namespace std;

#define readInt(num) scanf("%d", &num)
#define readLL(num) scanf("%lld", &num)
typedef long long int lli;

int t, n, q, x, y, decide;
lli money[100001], segTree[262143], getCurrTotal;

void buildSegTree(int low, int high, int rootPos)
{
    if(low == high)
    {
        segTree[rootPos] = money[low];
        return;
    }

    int mid = (low+high)/2;
    buildSegTree(low, mid, 2*rootPos+1);
    buildSegTree(mid+1, high, 2*rootPos+2);
    segTree[rootPos] = segTree[2*rootPos+1] + segTree[2*rootPos+2];
}

void updateMoney(int ind, int val, int low, int high, int rootPos, int type)
{
    if(ind <= low && ind>=high)
    {
        if(type == 1)
        {
            printf("%lld\n", segTree[rootPos]);

            segTree[rootPos] = 0;
        }
        else segTree[rootPos] += val;
        return;
    }
    if(ind < low || ind > high) return;

    int mid = (low+high)/2;

    updateMoney(ind, val, low, mid, 2*rootPos+1, type);
    updateMoney(ind, val, mid+1, high, 2*rootPos+2, type);
    segTree[rootPos] = segTree[2*rootPos+1] + segTree[2*rootPos+2];
}

lli query(int x, int y, int low, int high, int rootPos)
{
    if(x<=low && y>=high) return segTree[rootPos];
    if(x>high || y < low) return 0;

    int mid = (low+high)/2;
    lli val1 = query(x,y,low,mid,2*rootPos+1);
    lli val2 = query(x,y,mid+1,high,2*rootPos+2);
    return (val1+val2);
}

int main()
{
    freopen("input/in.txt","r",stdin);
    freopen("input/out.txt","w",stdout);
    readInt(t);

    for(int cs=1; cs<=t; cs++)
    {
        readInt(n); readInt(q);

        for(int i=0; i<n; i++) readLL(money[i]);

        buildSegTree(0,n-1,0);

        printf("Case %d:\n", cs);

        for(int i=0; i<q; i++)
        {
            readInt(decide);
            if(decide == 1)
            {
                readInt(x);
                updateMoney(x,0,0,n-1,0,1);
            }
            else if(decide == 2)
            {
                readInt(x); readInt(y);
                updateMoney(x,y,0,n-1,0,2);
            }
            else if(decide == 3)
            {
                readInt(x); readInt(y);
                printf("%lld\n", query(x,y,0,n-1,0));
            }
        }

    }

    return 0;
}

