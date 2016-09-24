//Segment tree.

#include <bits/stdc++.h>
using namespace std;

#define read(num) scanf("%d", &num)

int arr[100001], segTree[262143] = {INT_MAX};

/*int nextPowOf2(int n)
{
    n--;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    n++;
    return n;
}*/

void buildSegTree(int low, int high, int rootPos)
{
    if(low == high)
    {
        segTree[rootPos] = arr[low]; return;
    }
    int mid = (low+high)/2;
    buildSegTree(low,mid,2*rootPos+1);
    buildSegTree(mid+1,high,2*rootPos+2);
    segTree[rootPos] = min(segTree[2*rootPos+1],segTree[2*rootPos+2]);
}

int getMinimum(int qlow, int qhigh, int low, int high, int rootPos)
{
    if(qlow <= low && qhigh >= high) return segTree[rootPos];
    else if(qlow > high || qhigh < low) return INT_MAX;

    int mid = (low+high)/2;
    int val1 = getMinimum(qlow,qhigh,low,mid,2*rootPos+1);
    int val2 = getMinimum(qlow,qhigh,mid+1,high,2*rootPos+2);
    return min(val1,val2);
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t,n,q,x,y; read(t);

    for(int cs=1; cs<=t; cs++)
    {
        read(n); read(q);
        //int segTreeSz = 2*nextPowOf2(n)-1;
        for(int i=0; i<n; i++) read(arr[i]);
        buildSegTree(0,n-1,0);
        printf("Case %d:\n",cs);
        for(int i=1; i<=q; i++)
        {
            read(x); read(y);
            printf("%d\n",getMinimum(x-1,y-1,0,n-1,0));
        }
    }

    return 0;
}
