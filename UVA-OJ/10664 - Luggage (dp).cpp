#include <bits/stdc++.h>
using namespace std;

int t,n,sum;
vector<int>weight;
bool taken[20];

int dp[21][201];


int solve(int currPos,int currWeight)
{

    if(currPos == weight.size()) return 0;
    if(currWeight == sum/2) return 1;

    if(dp[currPos][currWeight] == -1)
    {
        int val1=0,val2=0, ret = 0;

        if(currWeight+weight[currPos] <= sum/2)
        {
            val1 = solve(currPos+1,currWeight+weight[currPos]);
        }
        val2 = solve(currPos+1, currWeight);

        ret = max(val1,val2);
        dp[currPos][currWeight] = ret;
    }

    return dp[currPos][currWeight];
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d", &t);

    for(int cs=1; cs<=t; cs++)
    {
        sum=0;
        while(scanf("%d", &n) != EOF)
        {
            //cout << n << " ";
            weight.push_back(n);
            sum+=n;
            if(cin.peek() == '\n') break;
        }
        //cout << endl;

        if(sum%2==1)
        {
            cout << "NO\n";
            weight.clear();
            continue;
        }

        memset(taken,false,sizeof taken);
        memset(dp,-1,sizeof dp);
        int result = solve(0,0);

        if(result == 1) cout << "YES\n";
        else cout << "NO\n";
        weight.clear();


    }

    return 0;
}

