#include <bits/stdc++.h>
using namespace std;

int t,n,sum;
vector<int>weight;
bool taken[20],found;


void solve(int currPos, int currWeight)
{
    if(currWeight == sum/2 && currPos == weight.size())
    {
        found = true;
        return;
    }
    else if(currWeight > sum/2 || currPos == weight.size()) return;

    for(int i=currPos; i<weight.size(); i++)
    {
        if(!taken[i])
        {
            taken[i] = true;

            solve(i+1, currWeight+weight[i]);

            taken[i] = false;
        }
    }
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

        found = false;
        memset(taken,false,sizeof taken);
        solve(0,0);

        if(found) cout << "YES\n";
        else cout << "NO\n";
        weight.clear();


    }

    return 0;
}
