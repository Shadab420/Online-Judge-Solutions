#include <bits/stdc++.h>
using namespace std;

char s1[1001], s2[1001];
long long int len1,len2,dp[1001][1001];

long long int LCS_Length(int i, int j)
{
    if(i == len1 || j == len2) return 0;

    if(dp[i][j] == -1)
    {
        if(s1[i] == s2[j])
        {
            dp[i][j] = 1+LCS_Length(i+1,j+1);
        }
        else
        {
            dp[i][j] = max(LCS_Length(i+1,j), LCS_Length(i,j+1));
        }
    }
    return dp[i][j];
}

/*long long int LCS_Length()
{
    int minLen = min(len1,len2);
    int maxLen = max(len1,len2);

    for(int i=0; i<minLen; i++)
    {
        for(int j=0; j<maxLen; j++)
        {
            if(s1[i] == s2[j])
            {
                dp[i][j] = 1+dp[i+1][j+1];
            }
            else
            {
                dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }


    return dp[minLen-1][maxLen-1];
}*/


int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    while(gets(s1) && gets(s2))
    {

        if(s1[0] == '\0' || s2[0] == '\0')
        {
            cout << 0 << endl; continue;
        }
        len1 = strlen(s1); len2 = strlen(s2);
        memset(dp,-1,sizeof dp);

        long long int ans = LCS_Length(0,0);
        //long long int ans = LCS_Length();
        cout << ans << endl;
    }

    return 0;
}
