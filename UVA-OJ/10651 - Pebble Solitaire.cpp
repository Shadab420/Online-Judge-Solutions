#include <bits/stdc++.h>
using namespace std;

#define read(num) scanf("%d", &num)

int n,m,set1;
char board[12];
int dp[1<<13];

bool checkRange(int ind, int type)
{
    if(type==1)
    {
        if(ind-2>=0) return true;
        else return false;
    }
    else
    {
        if(ind+2 <= 11) return true;
        else return false;
    }
}

bool check1(int mask, int pos)
{
    if(mask & (1<<pos)) return true;
    else return false;
}

int sett(int mask, int pos)
{
    return (mask | (1<<pos));
}

int reset(int mask, int pos)
{
    return (mask & ~(1<<pos));
}

int solve(int mask)
{
    if(dp[mask] != -1) return dp[mask];

    int cnt = __builtin_popcount(mask);

    //dp[mask] = 1000000000;

    int val1 = 0, val2 = 0;

    for(int i=0; i<12; i++)
    {
        int nextMask;

        if(checkRange(i,1) && !check1(mask,i) && check1(mask,i-1) && check1(mask,i-2))
        {
            nextMask = mask;
            nextMask = sett(nextMask,i);
            nextMask = reset(nextMask,i-1);
            nextMask = reset(nextMask,i-2);
            val1 = solve(nextMask);
            cnt = min(val1,cnt);
        }
        if(checkRange(i,2) && !check1(mask,i) && check1(mask,i+1) && check1(mask,i+2))
        {
            nextMask = mask;
            nextMask = sett(nextMask,i);
            nextMask = reset(nextMask,i+1);
            nextMask = reset(nextMask,i+2);
            val2 = solve(nextMask);
            cnt = min(val2,cnt);
        }
        //dp[mask] = cnt;
    }

    return dp[mask] = cnt;
}

int main()
{
    freopen("input/in.txt","r", stdin);
    freopen("input/out.txt","w", stdout);

    read(n);

    for(int i=0; i<n; i++)
    {
        scanf("%s", board);
        m=0;
        set1=1;
        for(int j=11; j>=0; j--)
        {
            if(board[j] == 'o') m|=set1;
            set1 <<= 1;
        }
//        for(int j = 11; j >= 0; j--)
//            if(m & (1 << j)) printf("1");
//            else printf("0");
//        puts(" ");

        //cout << m << endl;
        memset(dp,-1,sizeof dp);
        printf("%d\n", solve(m));
    }

    return 0;
}

