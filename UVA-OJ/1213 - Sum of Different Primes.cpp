#include <bits/stdc++.h>
using namespace std;


bool detectPrimes[1200];
vector<int>prime;
int n,k,cntComb;
long long int dp[1121][15][198];

void sieve()
{
    memset(detectPrimes, true, sizeof detectPrimes);

    for (int p=2; p*p<=1200; p++)
    {
        if (detectPrimes[p] == true)
        {
            for (int i=p*2; i<=1200; i += p) detectPrimes[i] = false;
        }
    }
    int i=1;
    for (int p=2; p<=1200; p++)
    {
        if(detectPrimes[p]) prime.push_back(p);
    }
}

long long int getComb(int sum, int cntNum, int i)
{
    if(cntNum == 0)
    {
        if(sum == 0) return 1;
        else return 0;
    }
    if(sum == 0) return 0;
    if(prime[i]>n) return 0;

    if(dp[sum][cntNum][i] == -1)
    {
        int val1=0, val2=0;

        if(sum-prime[i] >= 0)
        {
            val1 = getComb(sum-prime[i],cntNum-1,i+1);
            val2 = getComb(sum,cntNum,i+1);
        }


        dp[sum][cntNum][i] = val1+val2;

    }

    return dp[sum][cntNum][i];

}



int main()
{
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    sieve();

    //for(int i=0; i<prime.size(); i++) cout << prime[i] << endl;

    memset(dp,-1,sizeof dp);
    while(cin >> n >> k && n>0 && k>0)
    {
        cntComb = 0;

        long long int result = getComb(n,k,0);
        cout << result << endl;
    }

    return 0;
}
