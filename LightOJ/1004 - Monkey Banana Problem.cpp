#include <bits/stdc++.h>
using namespace std;

#define readInt(num) scanf("%d",&num)

int t,n,x,diamond[201][101];
long long int dp[201][101];

long long int maxKola(int i, int j)
{
    if(i<0 || i == 2*n-1 || j<0 || j==n) return 0;

    if(dp[i][j] == -1)
    {
        long long int val1 = 0, val2 = 0;

        if(i<n-1)
        {
            val1 = maxKola(i+1,j);
            val2 = maxKola(i+1,j+1);
        }
        else
        {
            val1 = maxKola(i+1,j-1);
            val2 = maxKola(i+1,j);
        }

        dp[i][j] = max(val1,val2) + diamond[i][j];
    }

    return dp[i][j];
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    readInt(t);
    int k;

    for(int cs=1; cs<=t; cs++)
    {
        readInt(n);
        k=1;
        for(int i=0; i<2*n-1; i++)
        {
            if(i<=n-1)
            {
                for(int j=0; j<=i; j++)
                {
                    readInt(diamond[i][j]);
                }
            }
            else
            {
                for(int j=0; j<i-k; j++)
                {
                    readInt(diamond[i][j]);
                }
                k+=2;
            }
        }
        memset(dp,-1,sizeof dp);
        long long int result = maxKola(0,0);
        cout << "Case " << cs << ": " << result << endl;

        /*for(int i=0; i<2*n-1; i++)
        {
            for(int j=0; j<n; j++)
            {
                cout << diamond[i][j] << " ";
            }
            cout << endl;
        }*/

        memset(diamond,0,sizeof diamond);


    }

    return 0;
}
