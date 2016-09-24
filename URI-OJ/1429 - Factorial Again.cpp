#include <bits/stdc++.h>

using namespace std;

int dp[100];

int fact(int x)
{
    if(x == 0 || x == 1) return 1;
    else
    {
        if(dp[x] == -1) dp[x] = x * fact(x-1);
    }
    return dp[x];
}

int main()
{
    freopen("i.txt","r",stdin);
    char num[5];
    while(cin >> num)
    {
        if(atoi(num) == 0) break;
        int len = strlen(num), sum = 0;
        memset(dp,-1,sizeof dp);
        int n = atoi(num);

        for(int i=1; i<=len; i++)
        {
            sum += (n%10) * fact(i);
            n/=10;
        }
        cout << sum << endl;
    }



    return 0;
}
