#include <bits/stdc++.h>
using namespace std;

int n,q,d,m;
long long int dp[201][11][51];
int number[201];

long long int solve(int currPos, int cntNum,int currSum)
{

    if(cntNum == m)
    {
        if(currSum == 0) return 1;
        else
        {
            return 0;
        }

    }
    if(currPos == n) return 0;


    if(dp[currPos][cntNum][currSum] == -1){

        long long int val1 = 0, val2 = 0, val3 = 0;

        val1 = solve(currPos+1, cntNum+1,(currSum+number[currPos])%d);
        val2 = solve(currPos+1,cntNum,currSum);

        val3 = val1+val2;

        dp[currPos][cntNum][currSum] = val3;

    }

    return dp[currPos][cntNum][currSum];

}

int main()
{
    freopen("input/in.txt", "r", stdin);
    freopen("input/out.txt", "w", stdout);

    int sett = 0;

    while(cin >> n >> q)
    {
        if(n==0 && q==0) break;
        sett++;


        for(int i=0; i<n; i++)
        {
            cin >> number[i];
        }
        cout << "SET " << sett << ":\n";

        for(int i=1; i<=q; i++)
        {
            cin >> d >> m;

            memset(dp,-1,sizeof dp);

            long long int result = solve(0,0,0);

            /*for(int a=0; a<d+1; a++){
                for(int b=0; b<m+1; b++){
                        for(int c=0; c<51; c++)
                        {
                            cout << dp[a][b][c] << " ";
                        }
                }
                cout << endl;
            }*/

            cout << "QUERY " << i << ": " << result << endl;
        }
    }
}


