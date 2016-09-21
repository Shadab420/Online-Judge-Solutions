#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int n, noOfTracks,sum,maxSum, bestCombination;

    while(cin >> n >> noOfTracks)
    {
        int duration[noOfTracks];
        for(int i=0; i<noOfTracks; i++) cin >> duration[i];

        int bitCombinations = 1 << noOfTracks;


        maxSum = 0;
        for(int i=0; i<bitCombinations; i++)
        {
            sum = 0;
            for(int j=0; j<noOfTracks; j++)
            {
                if((1<<j) & i)
                {
                    sum += duration[j];
                }
            }

            if(sum > maxSum && sum <=n)
            {
               maxSum = sum;
               bestCombination = i;
            }

        }

        for(int i=0; i<noOfTracks; i++)
        {
            if((1<<i) & bestCombination) cout << duration[i] << " ";
        }
        cout << "sum:" << maxSum << endl;
    }
    return 0;
}

