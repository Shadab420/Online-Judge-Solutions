#include <bits/stdc++.h>
using namespace std;

#define read(num) scanf("%d", &num)

struct Box
{
    int weight;
    int load;
};

vector<Box>boxes;
int n,dp[1001][6001];

int solve(int pos, int remainingLoad)
{
    if(pos >= n) return 0;

    if(dp[pos][remainingLoad] != -1) return dp[pos][remainingLoad];

    int val1 = 0, val2 = 0;

    if(boxes[pos].weight <= remainingLoad)
    {
        val1 = 1 + solve(pos+1, min(remainingLoad-boxes[pos].weight, boxes[pos].load));
    }
    val2 = solve(pos+1, remainingLoad);

    return dp[pos][remainingLoad] = max(val1, val2);
}

int main()
{
    freopen("input/in.txt","r", stdin);
    freopen("input/out.txt","w", stdout);

    Box b;

    while(read(n)!= EOF)
    {
        if(n==0) break;

        for(int i=1; i<=n; i++)
        {
            read(b.weight);
            read(b.load);
            boxes.push_back(b);
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<=3000; j++) dp[i][j] = -1;
            dp[i][6000] = -1;
        }

        printf("%d\n", solve(0,6000));

        boxes.clear();
    }

    return 0;
}
