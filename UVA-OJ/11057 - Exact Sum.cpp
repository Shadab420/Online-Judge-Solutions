#include <bits/stdc++.h>
using namespace std;

#define read(num) scanf("%d", &num)
vector<int>bookPrices;
int x,y,d;

void solve(int low, int high, int money)
{
    if(low >= high) return;
    int mid = (low+high)>>1;
    solve(low,mid,money); solve(mid+1,high,money);
    int j=high;
    for(int i=low; i<j;)
    {
        if(bookPrices[i] + bookPrices[j] > money) j--;
        else if(bookPrices[i] + bookPrices[j] < money) i++;
        else
        {
            if(bookPrices[j] - bookPrices[i] < d)
            {
                x = bookPrices[i]; y = bookPrices[j]; d = bookPrices[j] - bookPrices[i];
                i++; j--;
                //if(j==mid) j = high;
            }
        }
    }
}

int main()
{
    freopen("input/in.txt","r",stdin);
    freopen("input/out.txt","w",stdout);
    int n,p,m;

    while(read(n) !=EOF)
    {
        for(int i=0; i<n; i++)
        {
            read(p); bookPrices.push_back(p);
        }
        read(m);
        sort(bookPrices.begin(), bookPrices.end());
        d = INT_MAX;
        solve(0,n-1,m);
        printf("Peter should buy books whose prices are %d and %d.\n", x,y);
        bookPrices.clear();
        printf("\n");
    }

    return 0;
}
