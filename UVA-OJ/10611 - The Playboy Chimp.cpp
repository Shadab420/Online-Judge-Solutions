#include <bits/stdc++.h>
using namespace std;
#define read(num) scanf("%d", &num)

int height[50000], shorterTallest, tallerShortest,j;

void binarySearch(int l, int r, int luchu)
{
    int mid;
    while(l <= r)
    {
        mid = (l + r) >> 1;

        if(height[mid] > luchu && height[mid] < tallerShortest)
        {
            tallerShortest = height[mid];
            r = mid-1;
        }
        else if(height[mid] < luchu && height[mid] > shorterTallest)
        {
            shorterTallest = height[mid];
            l = mid+1;
        }
        else
        {
            if(mid-1>=0) shorterTallest = height[mid-1];
            if(mid+1 <= j) tallerShortest = height[mid+1];
            break;
        }

    }

}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int n,q,luchuHeight, i; read(n);

    read(height[0]);
    j = 1;
    for(i=1; i<n; i++)
    {
        read(height[j]);
        if(height[j] != height[j-1]) j++;
    }
    //for(int i=0; i<j; i++) cout << height[i] << " ";
    j--;
    read(q);
    for(i=0; i<q; i++)
    {
        read(luchuHeight);
        shorterTallest=0; tallerShortest = INT_MAX;

        binarySearch(0,j,luchuHeight);

        if(shorterTallest > 0) printf("%d ", shorterTallest);
        else printf("X ");
        if(tallerShortest < INT_MAX)  printf("%d\n", tallerShortest);
        else printf("X\n");
    }

    return 0;
}
