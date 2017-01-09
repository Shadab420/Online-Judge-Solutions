///Verdict: AC
#include <bits/stdc++.h>
using namespace std;

#define readInt(num) scanf("%d", &num)
#define read(num1, num2) scanf("%d %d", &num1, &num2)
typedef long long int lli;

int n;
int a, avg, arr[51];
lli dp[51][2501][51];

lli solve(int pos, int sum, int cnt)
{
    if(pos == n) return 0;

    if(dp[pos][sum][cnt] != -1) return dp[pos][sum][cnt];

    dp[pos][sum][cnt] = 0;

    lli val1=0, val2=0;

    //cout << sum+arr[pos] << " " << cnt +1 << endl;

    if(sum+arr[pos] == ((cnt+1)*a))
    {
        val1 = 1+ solve(pos+1, sum+arr[pos], cnt+1);
    }
    else val1 = solve(pos+1, sum+arr[pos], cnt+1);

    val2 = solve(pos+1,sum,cnt);

    return dp[pos][sum][cnt] += (val1+val2);

}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    while(read(n,a) != EOF)
    {
        for(int i=0; i<n; i++) readInt(arr[i]);
        memset(dp, -1, sizeof dp);
        //a = a * n;
        printf("%lld\n", solve(0, 0, 0));
    }

    return 0;
}
